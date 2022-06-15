#include <iostream>
#include "world.h"
#include "organism.h"
#include "ant.h"
#include "p_ant.h"

using namespace std;

PoisonuosAnt::PoisonuosAnt() : Ant(){ 
    //empty
}

PoisonuosAnt::PoisonuosAnt(World *world, int x, int y) : Ant(world,x,y){
    //empty
}

int PoisonuosAnt::getType(){
    return P_ANT;
}

void PoisonuosAnt::breed(){
    bool bred = false;
    breedTicks++;
    if (breedTicks == ANTBREED){
        breedTicks = 0;
// Try to make a new ant either above, left, right, or down
        if ((y>0) && (world->getAt(x,y-1)==NULL)){
            PoisonuosAnt *newAnt = new PoisonuosAnt(world,x,y-1);
            bred = true;
        }
        else if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)){
            PoisonuosAnt *newAnt = new PoisonuosAnt(world,x,y+1);
            bred = true;
        }
        else if ((x>0) && (world->getAt(x-1,y)==NULL)){
            PoisonuosAnt *newAnt = new PoisonuosAnt(world,x-1,y);
            bred = true;
        }
        else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL)){
            PoisonuosAnt *newAnt = new PoisonuosAnt(world,x+1,y);
            bred = true;
        }

        if(bred == false){
            if ((y>0) && world->grid[x][y-1]->getType() == ANT ){
                PoisonuosAnt *newAnt = new PoisonuosAnt(world,x,y-1);
                bred = true;
            }
            else if ((y<WORLDSIZE-1) && world->grid[x][y+1]->getType() == ANT ){
                PoisonuosAnt *newAnt = new PoisonuosAnt(world,x,y+1);
                bred = true;
            }
            else if ((x>0) && world->grid[x-1][y]->getType() == ANT ){
                PoisonuosAnt *newAnt = new PoisonuosAnt(world,x-1,y);
                bred = true;
            }
            else if ((x<WORLDSIZE-1) && world->grid[x+1][y]->getType() == ANT ){
                PoisonuosAnt *newAnt = new PoisonuosAnt(world,x+1,y);
                bred = true;
            }   
        }
    }
}
