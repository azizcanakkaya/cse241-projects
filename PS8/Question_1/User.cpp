#include "User.h"
#include "Security.h"
#include <iostream>
#include <string>

namespace GTU{

    bool User::Login(std::string username, std::string password){
        int temp = check.validate(username,password);
        //returning according to the output of check
        if( temp == 1 )
            return true;
        else
            return false;
    }

    User::User(){
        //empty
    }

}