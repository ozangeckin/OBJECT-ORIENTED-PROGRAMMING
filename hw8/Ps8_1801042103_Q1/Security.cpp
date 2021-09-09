//This is Security.cpp
#include <iostream>
#include <string>
#include "Security.h"

using namespace std;

// 1 if valid user, and 2 if valid administrator
int Security::validate(string username,string password)
{
    if((username=="abbott")&&(password=="monday"))return 1;
    
    if((username=="costello")&&(password=="tuesday"))return 2;
    
    return 0;

}