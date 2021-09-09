#ifndef ELF_H
#define ELF_H

#include "creature.h"

namespace Game{

    class Elf:public Creature
    {
        public:

            Elf();//no-parametre constructor
            Elf(int newStrength,int newHit);//two-parametre constructor
            int getDamage();
            string getSpecies() const;//return name of creature

    };

}
#endif