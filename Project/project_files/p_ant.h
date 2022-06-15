#ifndef P_ANT_H
#define P_ANT_H

#include <iostream>
#include "world.h"
#include "organism.h"
#include "ant.h"

class PoisonuosAnt : public Ant{
    friend class World;
    friend class Organism;
    public: 
        PoisonuosAnt();
        PoisonuosAnt(World *world, int x, int y);
        void breed();
        int getType();
};

#endif