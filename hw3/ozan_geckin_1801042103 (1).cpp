#include<iostream>
#include<fstream>
#include<vector>

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
class Image{//create image class
    public:
        Image(){}//No parameter constructor
        bool readPpm(string inputS);//reading the image file in .ppm format
        bool writePpm(string output);//writing the image file in .ppm format
        void grayScale(float c_r,float c_g,float c_b);//ıt changes every pixel of picture with the values it gets from the user.
    private:
        vector<vector<Pixel>> picture;//initiliaz 2D vector to be able to hold the data
        string format;
        int width;
        int height;
        int color;

};
bool Image::readPpm(string inputS){//if it can read ,returns true.
    string t="";//keep to color
    float b=0;//to keep the pixels in float
    vector<vector<Pixel>> picTemp;//ı hava defined the temp vector picture to be able to assignt.
    ifstream inputStream;//to read.
    inputStream.open(inputS);//open file.

    inputStream >> format;//check the format of the .ppm file
    if(format != "P3"){
        return false;
    }
    inputStream >> width >> height;//reading with and height values from .ppm file
    inputStream >> color;//reading instensity
    for(int i=0;i<height;i++){//reading pixel
        vector<Pixel> vec;//initliaz 1D pixel vector
        for(int j=0;j<width;j++){
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
            vec.push_back(temp);//vector add
        }
        
        picTemp.push_back(vec);//2D vector add
        
    }
    picture=picTemp;//I made this assignment to solve this problem, as long as the picture vector program continues, every read file will push back to the picture vectorune.
    return true;
}
bool Image::writePpm(string output){//if it can write ,returns true.
    ofstream outputStream;//to write
    outputStream.open(output);//open file
    outputStream << format <<endl;//writes format(P3)
    outputStream << width << " "<< height <<endl;//writes width and height
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
    for(int i=0; i<picture.size();i++){
        vector<Pixel> temp =picture[i];
        for(int j=0;j<temp.size();j++){
            if((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()) > 255){//check maksimum 255
                temp[j].setRed(255);
                temp[j].setGreen(255);
                temp[j].setBlue(255);
            }else{
            temp[j].setRed((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()));
            temp[j].setGreen((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()));
            temp[j].setBlue((c_r*picture[i][j].getRed())+(c_g*picture[i][j].getGreen())+(c_b*picture[i][j].getBlue()));
            }
        }
        picture[i]=temp;
    }
}
int cntrlString(string str){//Checks for string input instead of integer.(to prevent infinite loop)
 int temp;
 for(int i=0;i<str.length();i++){
    if(str[i]=='0' ||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'){
     temp=stoi(str);
    }
    else{
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
        exit(1);
    }
}
int main()
{
    Image pic;//create obje
    int choice,choice1,choice2,choice3,choice4;//I have defined for menu options.
    string c,c1,c2,c3,c4,cr,cg,cb;//I used to check the inputs.
    float c_r,c_g,c_b;//to keep red,green and blue coefficient.
    bool cntrl;// I have defined files for the respective controller
    string input;//to keep input file name
    string output;//to keep output file name

    do{//initiation  main menu
    cout << "\n Main Menu\n\n"
         << " 0 - Exit \n"
         << " 1 - Open An Image(D)\n"
         << " 2 - Save Image Data(D)\n"
         << " 3 - Scripts(D)\n\n"
         << " Enter your choice and press return: ";
    cin >> c;
    choice=cntrlString(c);//Check input(character ,string.. (wrong input)).
    switch (choice)
    {
        case 0:
            exit(1);
            break;
        case 1:
            do{//describe open an image menu
            cout<<"\n OPEN AN IMAGE MENU"<<endl
                <<" 0 - UP\n"
                <<" 1 - Enter The Name Of The Image File"<<endl;
            cin >> c1;
            choice1=cntrlString(c1);//Check input(character ,string.. (wrong input)).
            switch (choice1)
            {
                case 0:
                    break;
                case 1:
                    cin >> input;//file name
                    cntrl=pic.readPpm(input);//input.ppm file reading
                    if(cntrl==false){
                        exit(1);
                        break;
                    }
                    break;
                default:
                    exit(1);
                    break;
            }
            }while(choice1!=0);
            break;
        case 2:
            do{//describe save image data menu
            cout<<"\n SAVE IMAGE DATA MENU"<<endl
                <<" 0 - UP\n"
                <<" 1 - Enter A File Name"<<endl;
            cin >> c2;
            choice2=cntrlString(c2);//Check input(character ,string.. (wrong input)).
            switch (choice2)
            {
            case 0:  
                break;
            case 1:
                cin >> output;//file name
                cntrl=pic.writePpm(output);//output.ppm file writing
                if(cntrl==false){
                    exit(1);
                    break;
                }
                break;
            default:
                exit(1);
                break;
            }
            }while(choice2!=0);
            break;
        case 3:
            do{//describe scripts menu
            cout<<"\n SCRIPTS MENU"<<endl
                <<" 0 - UP\n"
                <<" 1 - Convert To Grayscale(D)"<<endl;
            cin >> c3;
            choice3=cntrlString(c3);//Check input(character ,string.. (wrong input)).
            switch (choice3)
            {
            case 0: 
                break;
            case 1:
                do{//describe convert to grayscale menu
                cout<<"\n CONVERT TO GRAYSCALE MENU"<<endl
                    <<" 0 - UP\n"
                    <<" 1 - Enter Coefficient For RED GREEN And BLUE Channels"<<endl;
                cin >> c4;
                choice4=cntrlString(c4);//Check input(character ,string.. (wrong input)).
                switch (choice4)
                {
                case 0:
                    break;
                case 1:
                    cin>>cr;
                    c_r=cntrlString2(cr);//checks coefficient red
                    cin>>cg;
                    c_g=cntrlString2(cg);//checks coefficient green
                    cin>>cb;
                    c_b=cntrlString2(cb);//checks coefficient blue
                    pic.grayScale(c_r,c_g,c_b);//calls the grayscale function to the pic object
                    break;
                default:
                    exit(1);
                    break;
                }
                }while(choice4 != 0);
                break;
            default:
                exit(1);
                break;
            }
            }while(choice3!=0);
            break;
        default:
        exit(1);
        break;
    }
    }while(choice!=0);
}