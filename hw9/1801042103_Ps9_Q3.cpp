#include<iostream>
#include<string.h>

using namespace std;

void reverse(char arr[],int a1,int a2);
void reverseString(char arr[]);

int main(){
   int ind1,ind2,leng;
   char arr[5]{'A','B','C','D','E'};
   char str[]="Gebze Technical University";

   cout<<"arr[0]=="<<arr[0]<<" "
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

   if(ind1<0 || ind2>=leng || ind1>=leng || ind2<0){
       cout<<"Error:Inverse bounds"<<endl;
       exit(1);
   }
   reverse(arr,ind1,ind2);

   cout<<"After reverse\n"
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

}

void reverse(char arr[],int a1,int a2){
    char temp;
    for(int i=a1,j=a2 ;i<j;i++,j--){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

void reverseString(char arr[]){
    int lowerBound=0;
    int highBound=strlen(arr)-1;
    reverse(arr,lowerBound,highBound);
}
