#include<iostream>
#include<string>
#include"user.h"
#include"administrator.h"

using namespace std;

int main(){
    //test
    Administrator admin("john","friday"),admin2("costello","tuesday");
    User user("jack","sunday"),user2("abbott","monday");

    cout<<"Checked sign in.."<<endl;
    cout<<"Admin login for john= "<<admin.login()<<endl;
    cout<<"Admin login for costello= "<<admin2.login()<<endl;
    cout<<"User login for jack= "<<user.login()<<endl;
    cout<<"User login for abbott= "<<user2.login()<<endl;

    return 0;
}