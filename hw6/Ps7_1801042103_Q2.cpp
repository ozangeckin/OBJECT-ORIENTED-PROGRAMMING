#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
        Student();//no parametre constructor
        Student& operator =(const Student& other);//assignment operator overloading
        ~Student();//destructor
        void inputData();//to input data
        string getName();//to getter name
        void outputData();//to output data
        void ResetClasses();//to reset data
    private:
        string name;//to keep name
        int numClasses;//to keep class count
        string * classList;//to keep class name
};
Student::Student():name(""),numClasses(0),classList(NULL){ //no parametre constructor
}
Student::~Student(){//destructor
    numClasses=0;
    ResetClasses();
    name="";
}
string Student::getName(){//return name
    return name;
}
void Student::inputData(){
    cout<<"Pleas enter student name : ";
    getline(cin,name);
    cout<<"Please enter number of classes : ";
    cin >> numClasses;
    cin.ignore(2,'\n');
    if(numClasses>0)
    {
        classList = new string[numClasses];//dynamic memory allocation
        for(int i=0;i<numClasses;i++){
            cout<<"Enter name of class "<<i+1<<" : ";
            getline(cin,classList[i]);
        }
    }
    cout<<endl;
}
void Student::outputData(){
    cout<<"Class List: "<<endl;
    for(int i=0;i<numClasses;i++){
        cout<<i+1<<"->"<<classList[i]<<endl;
    }
}
void Student::ResetClasses(){
    if(classList !=NULL){//to check classlist (NULL)
        delete[] classList;
        classList=NULL;
        numClasses=0;
    }
}
Student& Student::operator =(const Student& other){
    numClasses=other.numClasses;
    if(numClasses>0)
    {
        classList =new string[numClasses];
        for(int i=0;i<numClasses;i++){
            classList[i]=other.classList[i];
        }
    }
    return *this;
}

int main(){

    //test 
    Student student1,student2;
    student1.inputData();
    cout<<"Student "<<student1.getName()<<" information : "<<endl;
    student1.outputData();
    cout<<endl;
    student2.inputData();
    cout<<"Student 2's information : "<<endl;
    student2.outputData();

    cout<<endl<<"Student 2's resetting."<<endl;
    student2.ResetClasses();
    cout<<"Student 2's after resetting."<<endl;
    student2.outputData();

    cout<<"student 1 assignment to student 2"<<endl;
    student2=student1;
    cout<<endl<<"Student 2's information"<<endl;
    student2.outputData();
    
    return 0;
}