#ifndef ANT_H
#define ANT_H

#include <iostream>
#include "world.h"
#include "organism.h"

class Ant : public Organism{
    friend class World;
    public:
        Ant();
        Ant(World *world, int x, int y);
        void breed(); // Must define this since virtual
        void move(); // Must define this since virtual
        int getType(); // Must define this since virtual
        bool starve(){ return false; }
};


#endif