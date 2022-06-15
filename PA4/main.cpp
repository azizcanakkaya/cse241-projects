///////////////////////////////////////////////////////////////////////
//Author : Aziz Can Akkaya                                          ///
//Number : 1801042250                                               ///
///////////////////////////////////////////////////////////////////////

//standart library implementation
#include <iostream>
#include <cmath>
#include <ctime>

//libraries that we created
#include "creature.h"
#include "cyberdemon.h"
#include "elf.h"
#include "demon.h"
#include "human.h"
#include "balrog.h"

//namespace implementation/activation
using namespace std;
using namespace game;

int main(){
    srand (time(NULL));
    //random configuration to prevent repetition
    int i = 0;  //cycle parameter
    //creatures' object definitions
    Cyberdemon cyb;
    Elf ef;
    Human hm;
    Balrog bal;
    //printing output
    while( i < 100 ){
        cout << cyb.getSpecies() << " attacks for " << cyb.getDamage() << " points!" << endl;
        cout << ef.getSpecies() << " attacks for " << ef.getDamage() << " points!" << endl;
        cout << hm.getSpecies() << " attacks for " << hm.getDamage() << " points!" << endl;
        cout << bal.getSpecies() << " attacks for " << bal.getDamage() << " points!" << endl << endl;

        i++;
        
        int temp = time(NULL) + 0.5;

        while(temp > time(NULL));
    }

    return 0;
}