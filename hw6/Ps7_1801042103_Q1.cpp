#include<iostream>
#include<cstring>

using namespace std;

int main(){

    char *head,*tail,*nstr,temp;//I have defined char pointer and char variable.
    string str;//I have defined it to hold the string I will get from the user.
    int i=0;//I used to navigate the string inside the while loop.

    cout<< "Please Enter String: ";
    getline(cin,str);//I used the getline function, including the string spaces in the line.

    nstr=new char[str.size()];//we have created a char array until the string we have
    strcpy(nstr,str.c_str());//I just used char arraye to copy the string entered by the user

    head=&nstr[0];//I assigned a head to show the first value.
    tail=&nstr[str.size()-1];//I assigned to show tail the last value.

    while(head<=tail){//I check that I have not come to the end.
        temp=nstr[i];//i puts temp on the condition that it starts all over again
        nstr[i]=*tail;//i assigned the value the tail shows to the string,provided that it starts all over again.
        *tail=temp;//there is a temp assignment in the queue
        *tail--;//the pointer shown by the tail is dropping towards the heade
        *head++;//The pointer pointed to by headin is raised towards the holiday.
        i++;//It is used to get the values in the string one by one.
    }
    cout<<"Swapped ="<<nstr<<endl;
    return 0;
}