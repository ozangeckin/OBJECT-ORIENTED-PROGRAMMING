//  This is the header file for the user class.
#ifndef USER_H
#define USER_H

#include<string>
using namespace std;

class User{
    public:
        User();
        User(string name,string pass);
        bool login();
    private:
        string username;
        string password;
};
#endif