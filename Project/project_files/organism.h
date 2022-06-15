#ifndef ORGANISM_H
#define ORGANISM_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

class World;

class Organism{
    friend class World; 
    public:
        Organism();
        Organism(World *world, int x, int y);
        ~Organism();
        virtual void breed() = 0; 
        virtual void move() = 0; 
        virtual int getType() = 0; 
        virtual bool starve() = 0; 
    protected:
        int x,y; 
        bool moved; 
        int breedTicks; 
        World *world;
};

#endif