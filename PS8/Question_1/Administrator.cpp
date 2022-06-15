#include "Administrator.h"
#include "Security.h"
#include <iostream>
#include <string>

namespace GTU{

    bool Administrator::Login(std::string username, std::string password){
        //return for check object
        int temp = check.validate(username,password);
        //if return is 2 it will be the admin return
        if( temp == 2 )
            return true;
        else
            return false;
    }

    Administrator::Administrator(){
        //empty
    }

}
