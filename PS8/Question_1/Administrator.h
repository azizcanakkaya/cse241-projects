#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
//needed libraries and set of the library
#include "Security.h"

namespace GTU{
    class Administrator{
        public:
            Administrator();    //default constructor
            bool Login(std::string username, std::string password); //login fucntion
        private:
            Security check;     //Security object
    };
}

#endif 