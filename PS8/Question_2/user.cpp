#include <iostream>
#include "user.h"
#include <cstring>

namespace Authenticate{
    //setter
    void User::inputUserName(){
        do{ //a loop for to set username if conditions satisfied
            std::cout << "Enter your username (8 letter only)" << std::endl;
            std::cin >> username;
        }while(!isValid());
    }
    //getter
    std::string User::getUserName() const{
        return username;    
    }
    //if length is 8 returning true, else false
    bool User::isValid(){
        if( username.length() == 8 )
            return true;
        
        return false;
    }
    //default constructor
    User::User(){
        username = "########";
    }
}