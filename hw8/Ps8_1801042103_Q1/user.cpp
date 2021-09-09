//  This is the implementation file for the user class.
#include<iostream>
#include "user.h"
#include "Security.h"

User::User(){//constructor that initialzies empty
    username="";
    password="";
}
User::User(string name,string pass){//constructor that sets data
    username=name;
    password=pass;
}
bool User::login(){//check entries
    int cntrl;
    cntrl=Security::validate(username,password);
    if((cntrl==2)||(cntrl==1)){
        return true;
    }
    return false;
}