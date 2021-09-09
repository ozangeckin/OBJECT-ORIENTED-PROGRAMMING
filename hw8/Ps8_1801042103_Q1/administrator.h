//This is header file for Administrator class. 
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<string>
using namespace std;

class Administrator{
    public:
        Administrator();
        Administrator(string name,string pass);
        bool login();
    private:
        string username;
        string password;
};
#endif