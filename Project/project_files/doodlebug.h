#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include <iostream>
#include "world.h"
#include "organism.h"

class Doodlebug : public Organism{
    friend class World;
    public:
        Doodlebug();
        Doodlebug(World *world, int x, int y);
        void breed(); // Must define this since virtual
        void move(); // Must define this since virtual
        int getType(); // Must define this since virtual
        bool starve(); // Check if a doodlebug starves to death
        bool poisended();
    private:
        int starveTicks; // Number of moves before starving
        int poisonTimer;
};

#endif