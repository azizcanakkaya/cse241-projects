#ifndef USER_H
#define USER_H
//library definition and inclusion of needed libraries
#include <string>

namespace Authenticate{
    class User{
        public:
            User();             //default constructor

            void inputUserName();   //setter
            bool isValid();         //validation function
            std::string getUserName() const;    //setter
        private:
            std::string username;
    };

}

#endif