#include "world.h"
#include "organism.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

World::World(){
    int i,j;
    for (i=0; i<WORLDSIZE; i++){
        for (j=0; j<WORLDSIZE; j++){
            grid[i][j]=NULL;
        } 
    } 
}
World::~World(){
    int i,j;
    for (i=0; i<WORLDSIZE; i++){
        for (j=0; j<WORLDSIZE; j++){
            if (grid[i][j]!=NULL)
                delete (grid[i][j]);
        }
    } 
}

Organism* World::getAt(int x, int y){
    if ((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE))
        return grid[x][y];
    return NULL;
}

void World::setAt(int x, int y, Organism *org){
    if ((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE)){
        grid[x][y] = org;
    } 
}

void World::Display(){
    int i,j;
    cout << endl << endl;
    for (j=0; j<WORLDSIZE; j++){
        for (i=0; i<WORLDSIZE; i++){
            if (grid[i][j]==NULL)
                cout << "_";
            else if (grid[i][j]->getType()==ANT)
                cout << "o";
            else if( grid[i][j]->getType() == P_ANT)
                cout << "c";
            else 
                cout << "X";
        }
    cout << endl;
    }
}

void World::Step(){
    for (int x = 0; x < WORLDSIZE; x++){
    for (int y = 0; y < WORLDSIZE; y++){
      if (grid[x][y] == nullptr) continue;
      if (grid[x][y]->getType() == DOODLEBUG)
        grid[x][y]->move();
    }
  }

  for (int x = 0; x < WORLDSIZE; x++){
    for (int y = 0; y < WORLDSIZE; y++){
      if (grid[x][y] == nullptr) continue;
      if (grid[x][y]->getType() == ANT)
        grid[x][y]->move();
    }
  }

  for (int x = 0; x < WORLDSIZE; x++){
    for (int y = 0; y < WORLDSIZE; y++){
      if (grid[x][y] == nullptr) continue;
      if (grid[x][y]->getType() == P_ANT)
        grid[x][y]->move();
    }
  }

  for (int x = 0; x < WORLDSIZE; x++){
    for (int y = 0; y < WORLDSIZE; y++){
      if (grid[x][y] == nullptr) continue;
      grid[x][y]->breed();
    }
  }

  for (int x = 0; x < WORLDSIZE; x++){
    for (int y = 0; y < WORLDSIZE; y++){
      if (grid[x][y] == nullptr) continue;
      if (grid[x][y]->starve()){
        delete grid[x][y];
        grid[x][y] = nullptr;
      }
    }
  }
}

void World::Simulate(){

    int step = 0;
    int doodle = 0;
    int p_ant = 0;
    int ant = 0;

    while(1){
        string in;
        step++;

        for(int i = 0; i < WORLDSIZE; i++){
            for (int j = 0 ; j < WORLDSIZE; j++){
                if(grid[i][j]->getType() == DOODLEBUG)
                    doodle++;
                else if(grid[i][j]->getType() == ANT)
                    ant++;
                else if(grid[i][j]->getType() == P_ANT)
                    p_ant;
            }
        }
        Step();
        Display();
        cout << "Steps Simulated : " << step << endl
        << "Doodlebugs : " << doodle << endl
        << "Ants : " << ant << endl
        << "Poisonus Ants : " << p_ant << endl << endl
        << "Press Enter to contunie : ";
        cin >> in;
        system("clear"); 
    }
}



