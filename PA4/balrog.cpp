#include "creature.h"
#include <iostream>
#include "balrog.h"

namespace game{
    //defualt constructor
    Balrog::Balrog(){
        //setting the values of base class
        this->setType(2);
        this->setStrength(45);
        this->setHitpoint(200);
    }

    //constructor with parameters
    Balrog::Balrog(int newStrength, int newHit){
        //setting the values of base class
        this->setType(2);
        this->setStrength(newStrength);
        this->setHitpoint(newHit);
    }    

    //redefined getDamage function
    int Balrog::getDamage(){
        int critical,damage;
        //get a number for between 0 and 5 for %5 chance
        critical = rand() % 101;
        //damage calculation
        damage = ( rand() % this->getStrength() ) + 1;
        //control check for critical hit
        if( critical <= 5 ){
            std::cout << "  'Critical Hit!'  ";
            return 2*(damage + 50);
        }
        return damage*2;
    }
}