#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "creature.h"

namespace game{
    class Human : public Creature{
        public:
            //constructors
            Human();
            Human(int newStrength, int newHit);
    };
}

#endif