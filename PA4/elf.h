#ifndef ELF_H
#define ELF_H

#include <string>
#include "creature.h"

namespace game{
    class Elf : public Creature{
        public:
            //constructors
            Elf();
            Elf(int newStrength, int newHit);
            //redefined functions
            int getDamage();
    };
}

#endif