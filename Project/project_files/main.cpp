#include "organism.h"
#include "world.h"
#include "p_ant.h"
#include "ant.h"
#include "doodlebug.h"
#include <iostream>

using namespace std;

int main(){
    World w;
    srand(time(NULL)); // Seed random number generatorWorld w;
    int step = 0;

    int antcount = 0;
    while (antcount < INITIALANTS){
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        if (w.getAt(x,y)==NULL){
            antcount++;
            Ant *a1 = new Ant(&w,x,y);
        }
    }
// Randomly create 5 doodlebugs
    int doodlecount = 0;
    while (doodlecount < INITIALBUGS){
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        if (w.getAt(x,y)==NULL){
            doodlecount++;
            Doodlebug *d1 = new Doodlebug(&w,x,y);
        }
    }

    w.Display();

    //w.Simulate();    

    while( true ){
        string in;
        step++;

        cout << "before simulate" << endl;
        //w.Step();
        cout << "simulate" << endl;
        w.Display();
        cout << "Steps Simulated : " << step << endl
        << "Press Any Key and Enter to contunie : ";
        cin >> in;
        system("clear");
    }

    return 0;
}