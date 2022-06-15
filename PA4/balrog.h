#ifndef BALROG_H
#define BALROG_H

#include "demon.h"

namespace game{
    class Balrog : public Demon{
        public:
            //constructors
            Balrog();
            Balrog(int newStrength, int newHit);
            //redefined functions
            int getDamage();
    };
}

#endif