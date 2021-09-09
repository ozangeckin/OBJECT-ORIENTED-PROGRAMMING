#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class Pixel{//to hold the properties of a pixel(colors)
    public:
        Pixel():Pixel(0,0,0){};//No parameter constructor
        Pixel(float red_,float green_,float blue_):red(red_),green(green_),blue(blue_){};//three parameter constructor
        void setRed(float r_);//to set red
        void setGreen(float g_);//to set green
        void setBlue(float b_);//to set blue
        float getRed()const;//to access red data
        float getGreen()const;//to access green data
        float getBlue()const;//to access blue data
    private:
        float red;                                                                    
        float green;                                                                  
        float blue;        
};
//implement the setters,getters and operatings of the pixel class
void Pixel::setRed(float r_){
    red=r_;
}
void Pixel::setGreen(float g_){
    green=g_;
}
void Pixel::setBlue(float b_){
    blue=b_;
}
float Pixel::getRed()const{
    return red;
}
float Pixel::getGreen()const{
    return green;
}
float Pixel::getBlue()const{
    return blue;
}
class Image{
    public:
        Image();//no parametre constructor
        Image(const Image &old_obj);//copy constructor
        Image& operator=(const Image& other);//assignment operator
        ~Image();//destrutor
        bool readPpm(string inputS);//reading the image file in .ppm format
        bool writePpm(string output);//writing the image file in .ppm format
        void grayScale(float c_r,float c_g,float c_b);//ıt changes every pixel of picture with the values it gets from the user.
        void setName(string name_);//seting name
        string getName();//return name
        friend Image operator+(const Image& o1,const Image& o2);//+ operator overloading

    private:
        Pixel **picture;
        string format;
        string name;
        int width;
        int height;
        int color;
};

Image::Image(){//no parametre constructor:Creates an object with dimensions 10x10, format P3, color 255, and no name. 
        format="P3";
        name="";
        color=255;
        height=10;
        width=10;
        picture=new Pixel* [height];
        for(int i=0;i<height;i++){
            picture[i]=new Pixel[width];
        }
}
Image::~Image(){//destructor:Doing delete 2D dynamic array 
    for (int i = 0; i < width; i++)
        delete[] picture[i];
    delete[] picture;
    picture=nullptr;
}
Image& Image::operator=(const Image& other){//assignment operator overloading
    //if different dimension,delete and recreate.
    if((this->width!=other.width) && (this->height!=other.height)){//check size
         for (int i = 0; i < width; i++)
            delete[] picture[i];
        delete[] picture;
        picture=new Pixel* [other.height];
        for(int i=0;i<other.height;i++){
            picture[i]=new Pixel[other.width];
        }
    }  
    //assign data. 
    this->format=other.format;
    this->color=other.color;
    this->width=other.width;
    this->height=other.height;
    this->name=other.name;

    for(int j=0;j<height;j++){
        for(int q=0;q<width;q++){
            picture[j][q]=other.picture[j][q];
        }
    }
    return *this;//return obje.
}
void Image::setName(string name_){
    name.assign(name_);//assign name_ to name.
}
string Image::getName(){//return string name
    return name;
}
Image::Image(const Image& other){//copy constructor
    //if different dimension,delete and recreate.
    if((this->width!=other.width) && (this->height!=other.height)){//check size
       for (int i = 0; i < width; i++)
            delete[] picture[i];
        delete[] picture;
        picture=new Pixel* [height];
        for(int i=0;i<height;i++){
            picture[i]=new Pixel[width];
        }
    }
    //assign data.
    this->format=other.format;
    this->color=other.color;
    this->width=other.width;
    this->height=other.height;
    this->name=other.name;

    for(int j=0;j<height;j++){
        for(int q=0;q<width;q++){
            picture[j][q]=other.picture[j][q];
        }
    }
}
bool Image::readPpm(string inputS){
    string t="",x="",comment;
    string arr[4];
    int count=0;
    float b=0;//to keep the pixels in float
    ifstream inputStream;//to read.
    int tempWidth,tempHeight;
    tempHeight=height;
    tempWidth=width;
    inputStream.open(inputS);//open file.
    //check comment line.
    while(count<4){
    inputStream>>x;
    if(x[0]=='#'){
        do{
            getline(inputStream,comment);
            inputStream >> x;
        }while(x[0]=='#');
    }
    arr[count]=x;
    count++;
    }
    format=arr[0];
    width=stoi(arr[1]);
    height=stoi(arr[2]);
    color=stoi(arr[3]);

   if((this->width!=tempWidth) && (this->height!=tempHeight)){//check size
       //if different dimension,delete and recreate.
       for (int i = 0; i < width; i++)
            delete[] picture[i];
        delete[] picture;
        picture=new Pixel* [height];
        for(int i=0;i<height;i++){
            picture[i]=new Pixel[width];
        }
    } 
   
    for(int j=0;j<height;j++){
       // Pixel pix = new Pixel[width];
        for(int q=0;q<width;q++){
            Pixel temp;//template pixel obje
            inputStream>>t;//read
            b=stof(t);//string to float
            temp.setRed(b);//set red
            inputStream>>t;//read
            b=stof(t);//string to float
            temp.setGreen(b);//set green
            inputStream>> t;//read
            b=stof(t);//string to float
            temp.setBlue(b);//set blue
            picture[j][q]=temp;
        }
    }
return true;
}
bool Image::writePpm(string output){//if it can write,returns true.
    ofstream outputStream;//to write
    outputStream.open(output);//open file
    outputStream << format <<endl;//writes format(P3)
    outputStream<<width<<" "<<height<<endl;//writes width and height
     if(width == 0 || height == 0){//checks if it is empty
        return false;
    }
    outputStream<<color<<endl;//writing instensity
    for(int i=0; i<height;i++){
        for(int j=0;j<width;j++){
            if((j == width-1)){//end of column
            outputStream << picture[i][j].getRed()<<" "<<picture[i][j].getGreen()<<" "<<picture[i][j].getBlue();//writes the pixels
            }else{           
            outputStream << picture[i][j].getRed()<<" "<<picture[i][j].getGreen()<<" "<<picture[i][j].getBlue()<<" ";//writes the pixels
            }
        if(i== height-1 && j==width-1){//check line endings
        }else{
        outputStream<<endl;
        }
        }
    }
    outputStream.close();//output file close

    return true;
}
void Image::grayScale(float c_r,float c_g,float c_b){
    Pixel temp;
    for(int i=0;i<width;i++){
        //Pixel temp=picture[i];
        for(int j=0;j<height;j++){
        if((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()) > 255){//check maksimum 255
                temp.setRed(255);
                temp.setGreen(255);
                temp.setBlue(255);
            }else{
            temp.setRed((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()));
            temp.setGreen((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()));
            temp.setBlue((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()));
            }
           picture[i][j]=temp;   
        }
      
    }
}
Image operator +(const Image& o1,const Image& o2){//+ operator overloading
    if((o1.width != o2.width ) && (o1.height != o2.height)){
        cout<<" Error : The dimensions of the objects are not equal"<<endl;
    }
    Image result;
    Pixel temp;
    
   if((result.width!=o1.width) && (result.height!=o1.height)){//check size
       //if different dimension,delete and recreate.
       for (int i = 0; i < result.width; i++)
            delete[] result.picture[i];
        delete[] result.picture;
        result.picture=new Pixel* [o1.height];
        for(int i=0;i<o1.height;i++){
            result.picture[i]=new Pixel[o1.width];
        }
    } 
    result.width=o1.width;
    result.height=o1.height;
    result.color=o1.color;
    result.format=o1.format;
    result.name="addImage";

    for(int i=0;i<result.height;i++){
        for(int j=0;j<result.width;j++)
        {
            //check pixellerin toplamı 255,if more than 255 is set to 255.
            if(o1.picture[i][j].getRed()+o2.picture[i][j].getRed()>255){
                result.picture[i][j].setRed(255);
            }else{
                result.picture[i][j].setRed(o1.picture[i][j].getRed()+o2.picture[i][j].getRed());
            }
            if(o1.picture[i][j].getGreen()+o2.picture[i][j].getGreen()>255){
                result.picture[i][j].setGreen(255);
            }else{
                result.picture[i][j].setGreen(o1.picture[i][j].getGreen()+o2.picture[i][j].getGreen());
            }
            if(o1.picture[i][j].getBlue()+o2.picture[i][j].getBlue()>255){
                result.picture[i][j].setBlue(255);
            }else{
                result.picture[i][j].setBlue(o1.picture[i][j].getBlue()+o2.picture[i][j].getBlue());
            }
        }
    }
    return result;//return obje.
}
int cntrlString(string str){//Checks for string input instead of integer.(to prevent infinite loop)
 int temp;
 for(int i=0;i<str.length();i++){
    if(str[i]=='0' ||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
     temp=stoi(str);
    }
    else{
     cout<<" Error:Entered the wrong input"<<endl;
     exit(1);
    }
 }
 return temp;
}

float cntrlString2(string str){//Checks for float input(to prevent infinite loop)
    float temp;
    bool cntrl;
    for(int i=0;i<str.length();i++){
        if(i==1){
            i++;
        }if(str[0]=='0'&& str.length()==1){
            cntrl=true;
            break;
        }if( str[i]>46 && str[i]<=57 && str[1]=='.'){
            cntrl=true;
        }else{
            cntrl=false;
            exit(1);
        }
    }   
    if(cntrl==true){
        temp=stof(str);
    }
    if(temp>=0 && temp<1){
        return temp;
    }else{
        cout<<" Error : coefficient must be between [0,1) "<<endl;
        exit(1);
    }
}

void menu(){
   int choice,choice1,choice2,choice3,choice4,choice5,choice6,choice7,count;////I have defined for menu options.
   string c,c1,c2,c3,c4,c5,c6,c7,cr,cg,cb;//I used to check the inputs.
   float c_r,c_g,c_b;//to keep red,green and blue coefficient.
   bool cntrl;// I have defined files for the respective controller
   Image pic,pic2,add;//create objes
   string input;//to keep input files name
   string output;//to keep outpu file name
    do{ //launch main menu
       cout << "\n Main Menu\n\n"
         << " 0 - Exit \n"
         << " 1 - Open(Load) Images(D)\n"
         << " 2 - Save Images Data(D)\n"
         << " 3 - Scripts(D)\n"
         << " Enter your choice and press return: ";
        cin>>c;
        choice=cntrlString(c);//Check input(character ,string.. (wrong input)).
        if(choice==0){
            cout<<"\n EXITING..."<<endl;
            exit(1);
        }
        else if(choice==1){
            do{//describe open an image menu
                cout<<"\n OPEN(LOAD) IMAGES MENU"<<endl
                    <<" 0 - UP\n"
                    <<" 1 - Enter The Name Of The Image File(D)"<<endl;
                cin >> c1;
                choice1=cntrlString(c1);//Check input(character ,string.. (wrong input)).
                if(choice1==0){
                    break;
                }
                else if(choice1==1){
                    cout<<"\n How many images would you like to load (one or two)?\n Enter : ";
                    cin>>count;
                    if(count==1){
                        cout<<" Enter file name to read (obje1): ";
                        cin >> input;//file name
                        cntrl=pic.readPpm(input);//input.ppm file reading
                        if(cntrl==false){
                            cout<<" Error:File not found"<<endl;
                            exit(1);
                        }
                        pic.setName(input);
                    }
                    else if(count==2){
                        cout<<" Enter file name to read (obje1): ";
                        cin >> input;//file name
                        cntrl=pic.readPpm(input);//input.ppm file reading
                        if(cntrl==false){
                            cout<<" Error:File not found"<<endl;
                            exit(1);
                        }
                        pic.setName(input);
                        cout<<" Enter file name to read (obje2): ";
                        cin >> input;//file name
                        cntrl=pic2.readPpm(input);//input.ppm file reading
                        if(cntrl==false){
                            cout<<" Error:File not found"<<endl;
                            exit(1);
                        }
                        pic2.setName(input);
                        
                    }else{
                        cout<<" Error:Entered the wrong input"<<endl;
                        exit(1);
                    }
                }else{
                    cout<<" Error:Entered the wrong input"<<endl;
                    exit(1);
                }
            }while(choice1!=0);
        }else if(choice==2){
            do{//describe save image data menu
                cout<<"\n SAVE IMAGE DATA MENU"<<endl
                    <<" 0 - UP\n"
                    <<" 1 - Choose A File Name(D)"<<endl;
                cin>>c2;
                choice2=cntrlString(c2);//Check input(character ,string.. (wrong input)).
                if(choice2==0){
                    break;
                }else if(choice2==1){
                    do{
                    cout<<" Which image would you like to save?\n"
                        <<" 0 - UP\n"
                        <<" 1 - "<<pic.getName()<<"\n"
                        <<" 2 - "<<pic2.getName()<<"\n"
                        <<" 3 - "<<add.getName()<<endl;
                    cin>>c3;
                    choice3=cntrlString(c3);//Check input(character ,string.. (wrong input)).
                    if(choice3==0){
                        break;
                    }
                    else if(choice3==1){
                        cout<<" Enter file name to write : ";
                        cin >> output;//file name
                        cntrl=pic.writePpm(output);//output.ppm file writing
                        if(cntrl==false){
                        exit(1);
                        }
                    }else if(choice3==2){
                        cout<<" Enter file name to write : ";
                        cin >> output;//file name
                        cntrl=pic2.writePpm(output);//output.ppm file writing
                        if(cntrl==false){
                        exit(1);
                        }
                    
                    }else if(choice3==3){
                        cout<<" Enter file name to write : ";
                        cin >> output;//file name
                        cntrl=add.writePpm(output);//output.ppm file writing
                        if(cntrl==false){
                        exit(1);
                        }
                    }
                    else{
                        cout<<" Error:Entered the wrong input"<<endl;
                        exit(1);
                    }
                    }while (choice3!=0);
                }else{
                    cout<<" Error:Entered the wrong input"<<endl;
                    exit(1);
                }

            }while(choice2!=0);

        }else if(choice==3){
            do{//describe scripts menu
                cout<<"\n SCRIPTS MENU"<<endl
                    <<" 0 - UP\n"
                    <<" 1 - Convert To Grayscale(D)\n"
                    <<" 2 - Addition(D)"<<endl;
                cin >> c4;
                choice4=cntrlString(c4);//Check input(character ,string.. (wrong input)).
                if(choice4==0){
                    break;
                }else if(choice4==1){
                   do{//describe convert to grayscale menu
                    cout<<" Which image would you like to covert to grayscale?\n"
                        <<" 0 - UP\n"
                        <<" 1 - "<<pic.getName()<<"\n"
                        <<" 2 - "<<pic2.getName()<<"\n"
                        <<" 3 - "<<add.getName()<<endl;
                    cin >>c5;
                    choice5=cntrlString(c5);//Check input(character ,string.. (wrong input)).
                    if(choice5==0){
                        break;
                    }else if(choice5==1 || choice5==2 || choice5==3){                    

                        do{
                            cout<<"\n CONVERT TO GRAYSCALE MENU"<<endl
                                <<" 0 - UP\n"
                                <<" 1 - Enter Coefficient For RED GREEN And BLUE Channels"<<endl;
                            cin >> c6;
                            choice6=cntrlString(c6);
                            if(choice6==0){
                                break;
                            }else if(choice6==1){
                                if(choice5==1){
                                    cin>>cr;
                                    c_r=cntrlString2(cr);//checks coefficient red
                                    cin>>cg;
                                    c_g=cntrlString2(cg);//checks coefficient green
                                    cin>>cb;
                                    c_b=cntrlString2(cb);//checks coefficient blue
                                    pic.grayScale(c_r,c_g,c_b);//calls the grayscale function to the pic object
                                    break;
                                }else if(choice5==2){
                                    cin>>cr;
                                    c_r=cntrlString2(cr);//checks coefficient red
                                    cin>>cg;
                                    c_g=cntrlString2(cg);//checks coefficient green
                                    cin>>cb;
                                    c_b=cntrlString2(cb);//checks coefficient blue
                                    pic2.grayScale(c_r,c_g,c_b);//calls the grayscale function to the pic object
                                    break;
                                    
                                }else if(choice5==3){
                                    cin>>cr;
                                    c_r=cntrlString2(cr);//checks coefficient red
                                    cin>>cg;
                                    c_g=cntrlString2(cg);//checks coefficient green
                                    cin>>cb;
                                    c_b=cntrlString2(cb);//checks coefficient blue
                                    add.grayScale(c_r,c_g,c_b);//calls the grayscale function to the pic object
                                    break;
                                }
                                
                            }else{
                                cout<<" Error:Entered the wrong input"<<endl;
                                exit(1);
                            }
                        }while(choice6!=0);
                    }else{
                        cout<<" Error:Entered the wrong input"<<endl;
                        exit(1);
                    }

                    }while(choice5!=0);
                    
                }else if(choice4==2){
                    cout<<"\n ADDITION\n"<<endl;
                    if(pic.getName()=="" && pic2.getName()==""){
                        cout<<" Error:Objects are empty"<<endl;
                            exit(1);
                    }else{  
                        cout<<" Addition "<<pic.getName()<<" + "<<pic2.getName()<<",You can view save menu and convert to grayscale"<<endl;
                        add=pic+pic2;
                    }
                }
                else{
                    cout<<" Error:Entered the wrong input"<<endl;
                    exit(1);
                }

            }while(choice4!=0);

        }
        else{
            cout<<" Error:Entered the wrong input"<<endl;
            exit(1);
        }
    }while(choice!=0);
}
int main(){
  menu();
}