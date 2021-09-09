#include<iostream>
#include<cstdlib>
using namespace std;

class CharPair
{
    public:
    CharPair();
    CharPair(int sz);
    CharPair(int sz,char arr[]);
    void setSize(int size_);
    int getSize();
    char& operator[](int index);
  
    private:
    char array[100];
    int size;
};

CharPair::CharPair(){
    size=10;
    for(int i=0;i<size;i++){
        array[i]='#';
    }
}
CharPair::CharPair(int sz){
    setSize(sz);
    for(int i=0;i<size;i++){
        array[i]='#';
    }
    
}
CharPair::CharPair(int sz,char arr[]){
    setSize(sz);
    for(int i=0;i<size;i++){
        array[i]=arr[i];
    }
    for(int i=0;i<size;i++){
        arr[i]=array[i];
    }
}
void CharPair::setSize(int size_){
    size=size_;
}
int CharPair::getSize(){
    return size;
}
char& CharPair::operator [](int index){
    if(index>=0 && index<size){
        return array[index];
    }else{
        cout<<"Wrong index number"<<endl;
        exit(1);
    }
}

int main(){
    //test
    CharPair a;
    cout<<"No parametre constructor"<<endl;
    for(int i=0;i<a.getSize();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    char ar[3];
    cout<<"Obje created with no parametre constructor and index=5 =>"<< a[5]<<endl;
    CharPair b(5);
    b[1]='A';
    b[2]='B';
    cout<<"a[1] and a[2] are:\n";
    cout<<a[1]<<a[2]<<endl;
    cout<<"Enter two letters (no space):\n";
    cin>>a[1]>>a[2];
    cout<<"You entered:\n";
    cout<<a[1]<<a[2]<<endl;

    cout<<"Obje b created with one parametre constructor size "<<b.getSize()<<" index=3 "<<b[3]<<endl;
    CharPair c(8,ar);
    cout<<"Obje c created with two parametre consturctor size "<<c.getSize()<<endl;
    cout<<"Obje a created with no parametre constructor and index=152 =>"<< a[152]<<endl;
    
    return 0;
 }