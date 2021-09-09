//  This is the implementation file for the Administrator class.
#include<iostream>
#include<string>
#include"administrator.h"
#include"Security.h"

using namespace std;

Administrator::Administrator(){//Constructor that initializes empty
    username="";
    password="";
}
Administrator::Administrator(string name,string pass){//constructor that sets username and password
    username=name;
    password=pass;
}
bool Administrator::login(){//check entries.
    int cntl;
    cntl=Security::validate(username,password);
    if(cntl==2){
        return true;
    }
    return false;
}