#ifndef WORLD_H
#define WORLD_H

#include "organism.h"

const int WORLDSIZE = 20;
const int INITIALANTS = 100;
const int INITIALBUGS = 5;
const int DOODLEBUG = 1;
const int ANT = 2;
const int P_ANT = 3;
const int ANTBREED = 3;
const int DOODLEBREED = 8;
const int DOODLESTARVE = 3;
const int P_ANTBREED = 4;

class World{

    friend class Organism;
    friend class Doodlebug; 
    friend class Ant; 
    friend class PoisonuosAnt;
    public:
        World();
        ~World();
        Organism* getAt(int x, int y);
        void setAt(int x, int y, Organism *org);
        void Display();
        void Step();
        void Simulate();
    protected:
        Organism* grid[WORLDSIZE][WORLDSIZE];
};

#endif