#include "creature.h"
#include <iostream>
#include <string>
#include <cmath>

namespace game{
    //default constructor 
    Creature::Creature() : type(4), strength(1000), hitpoint(1000){
        //empty
    }

    //constructor with parameters
    Creature::Creature(int newType, int newStrength, int newHit) : type(newType), strength(newStrength), hitpoint(newHit){
        //empty
    }

    std::string Creature::getSpecies(){
        //checking what type of species is and returning according to it
        switch (type){
            case 0:
                return "Human";
            case 1:
                return "Cyberdemon";
            case 2:
                return "Balrog";
            case 3:
                return "Elf";
        }
        return "Unknown";
    }

    int Creature::getDamage(){
        int damage = ( rand() % strength ) + 1;
        return damage;
    }
}