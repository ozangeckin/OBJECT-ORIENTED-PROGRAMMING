#include<iostream>
using namespace std;

class MyInteger{//create class
    public:
        MyInteger(){}//no parametre constructor
        void setSize(int s);//set size
        void setArr(int s, int *p);//set array
        int getSize();//return size
        const int& operator[](int index);//[] operator overloading
    private:
        int *arr;
        int size;
};
void MyInteger::setSize(int s){
    size=s;
}
int MyInteger::getSize(){
    return size;
}
void MyInteger::setArr(int s,int *p){
    arr = new int[s];
    for(int i=0;i<s;i++){
        arr[i]=p[i];
    }
}
const int& MyInteger::operator[](int index){
    if(index>=size){
        cout<<"Array index out of bound,exiting"<<endl;
        exit(1);
        }else{
        return arr[size-index-1];
   }
}
int main(){
    //test
    MyInteger obje;//initilaz obje
    int s,temp;
    int* arr;
    cout<<"Enter Array Size: ";
    cin>>s;//size
    obje.setSize(s);
    if(s !=0){
        arr =new int[s];
        cout<<"Enter "<<s<<" number"<<endl;
        for(int i=0;i<s;i++){
            cin>>temp;
            arr[i]=temp;
            }
        }
    for(int i=0;i<s;i++){
        cout<<arr[i];
    }
    cout<<endl;
    obje.setArr(s,arr);
    cout<<"obje[0] = "<<obje[0]<<endl;
    cout<<"obje[1] = "<<obje[1]<<endl;
    cout<<"obje[2] = "<<obje[2]<<endl;
    cout<<"obje[3] = "<<obje[3]<<endl;    
}