#include "Security.h"
#include <iostream>
#include <string>
#include <cstdlib>

namespace GTU{

    using namespace std;

    Security::Security(){
        //empty
    }
    //check for input and returning it. 2 for admin, 1 for user and 0 for invalid output
    int Security::validate(string username, string password){
        if( (username == "abbott") && (password == "monday")){
            return 1;
        }
        else if( (username == "costello") && (password == "tuesday"))
            return 2;
        return 0;
    }
}