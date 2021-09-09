#ifndef DEMON_H
#define DEMON_H

#include"creature.h"

namespace Game{
    class Demon:public Creature
    {    
        public:
            Demon();//no-parametre constructor
            Demon(int newType,int newStrength,int newHit);//two-parametre constructor
            int getDamage();
            string getSpecies()const;//return name of creature
    };
}
#endif