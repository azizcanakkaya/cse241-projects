#ifndef CREATURE_H
#define CREATURE_H

#include <string>

namespace game{
    class Creature{
        public:
            //constructors
            Creature();                                         //default constructor
            Creature(int newType, int newStrength, int newHit); //constructor with parameters
            
            //class functions
            int getDamage();
            std::string getSpecies();
            
            //getters
            int getStrength() const { return strength; }
            int getHitpoint() const { return hitpoint; }
            int getType() const { return type; }
            
            //setters
            void setType(int newType) { type = newType; }
            void setStrength(int newStrength) { strength = newStrength; }
            void setHitpoint(int newHit) { hitpoint = newHit; }

        private:    //data
            int type, strength, hitpoint;
    };
}

#endif