#include "creature.h"
#include <iostream>
#include "elf.h"

namespace game{
    //defualt constructor
    Elf::Elf(){
        //setting the values of base class
        this->setType(3);
        this->setStrength(70);
        this->setHitpoint(250);
    }

    //constructor with parameters
    Elf::Elf(int newStrength, int newHit){
        //setting the values of base class
        this->setType(3);
        this->setStrength(newStrength);
        this->setHitpoint(newHit);
    }    

    //redefined getDamage function
    int Elf::getDamage(){
        int critical,damage;
        //get a number for between 0 and 10 for %10 chance
        critical = rand() % 101;
        //damage calculation
        damage = ( rand() % this->getStrength() ) + 1;
        //control check for critical hit
        if( critical <= 10 ){
            std::cout << "  'Critical Hit!'  ";
            return damage*2;
        }
    
        return damage;
    }
}