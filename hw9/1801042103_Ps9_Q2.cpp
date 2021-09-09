#include<iostream>
#include<string.h>

using namespace std;

void reverse(char arr[],int a1,int a2);
void mySwap(char arr[],int a,int b);
void reverseString(char arr[]);

int main(){
   int ind1,ind2,leng;
   char arr[5]{'A','B','C','D','E'};
   char str[]="Gebze Technical University";

   cout<<"\narr[0]=="<<arr[0]<<" "
       <<"arr[1]=="<<arr[1]<<" "
       <<"arr[2]=="<<arr[2]<<" "
       <<"arr[3]=="<<arr[3]<<" "
       <<"arr[4]=="<<arr[4]<<endl;
   cout<<"Choose which indexes to switch between"<<endl;
   cout<<"First index : ";
   cin>>ind1;
   cout<<"Second index : ";
   cin>>ind2;
   
   leng=strlen(arr);

   if(ind1<0 || ind2>leng || ind1>leng || ind2<0){
       cout<<"Error:Inverse bounds"<<endl;
       exit(1);
   }
   reverse(arr,ind1,ind2);

   cout<<"\nAfter reverse\n"
       <<"arr[0]=="<<arr[0]<<" "
       <<"arr[1]=="<<arr[1]<<" "
       <<"arr[2]=="<<arr[2]<<" "
       <<"arr[3]=="<<arr[3]<<" "
       <<"arr[4]=="<<arr[4]<<endl;


   cout<<"\nString\n"
       <<str<<endl;
    
   reverseString(str);
   cout<<"\nAfter reverse string\n"
       <<str<<endl;

    return 0;
}   

void reverse(char arr[],int a1,int a2){
    if(a1>=a2 ) {
        return;
    }else{
       
        mySwap(arr,a1,a2);
        reverse(arr,a1+1,a2-1);
    }
}
void mySwap(char arr[],int a,int b){
    char temp;
    temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void reverseString(char arr[]){
    int lowerBound=0;
    int highBound=strlen(arr)-1;
    reverse(arr,lowerBound,highBound);
}
