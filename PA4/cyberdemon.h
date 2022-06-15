#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "demon.h"

namespace game{
    class Cyberdemon : public Demon{
        public:
            //constructors
            Cyberdemon();
            Cyberdemon(int newStrength, int newHit);
            //redefined functions
            int getDamage();
    };
}

#endif