#ifndef USER_H
#define USER_H

#include "Security.h"

namespace GTU{
    class User{
        public:
            User(); //default consturctor
            bool Login(std::string username, std::string password); //login function for validation
        private:
            Security check;
    };
}

#endif 