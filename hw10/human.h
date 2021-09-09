#ifndef HUMAN_H
#define HUMAN_H

#include"creature.h"

namespace Game{

    class Human:public Creature{

        public:

            Human();//no-parametre constructor
            Human(int newStrengt,int newHit);//two-parametre constructor
            int getDamage();
            string getSpecies() const;//return name of creature

    };
    
}
#endif