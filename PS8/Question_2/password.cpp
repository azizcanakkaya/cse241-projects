#include <iostream>
#include "password.h"
#include <cstring>

namespace Authenticate{

    void Password::inputPassword(){
        //loop for input until it is valid
        do{
            std::cout << "Enter your password (at least 8 letter "
            << "and at least one non letter)" << std::endl;
            std::cin >> password;
        }while(!isValid());
    }
    //getter for password
    std::string Password::getPassword() const{
        return password;
    }

    bool Password::isValid(){
        //counters for check
        int non_letter = 0;
        int letter = 0;
        //setting size of char array
        char pass[ password.length() + 1];
        //copying string elements to the char array
        std::strcpy(pass,password.c_str());
        //for loop for counters
        for(int i = 0; i < password.length() + 1; i++ ){
            //checking if the cell is an digit or not
            if( pass[i] == '0' || pass[i] == '1' ||  pass[i] == '2' ||  pass[i] == '3' || 
             pass[i] == '4' ||  pass[i] == '5' ||  pass[i] == '6' || pass[i] == '7' || pass[i] == '8' || 
             pass[i] == '9')
                non_letter++;
            else
                letter++;
        }
        //if array contains a digit and length is greater than 8 returning true, else false
        if( non_letter != 0 && letter != 0 && password.length() >= 8 )
            return true;

        return false;
    }

    Password::Password(){
        password = "#######1";
    }

}