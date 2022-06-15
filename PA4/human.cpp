#include "creature.h"
#include <iostream>
#include "human.h"

namespace game{
    //defualt constructor
    Human::Human(){
        //setting the values of base class
        this->setType(0);
        this->setStrength(50);
        this->setHitpoint(100);
    }

    //constructor with parameters
    Human::Human(int newStrength, int newHit){
        //setting the values of base class
        this->setType(0);
        this->setStrength(newStrength);
        this->setHitpoint(newHit);
    }    
}