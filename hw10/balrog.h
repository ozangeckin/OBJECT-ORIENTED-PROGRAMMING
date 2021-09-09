#ifndef BALROG_H
#define BALROG_H

#include"demon.h"

namespace Game{

    class Balrog:public Demon{

        public:

            Balrog();//no-parametre constructor
            Balrog(int newStrength,int newHit);//two-parametre constructor
            int getDamage();
            string getSpecies() const;//return name of creature

    };
    
}
#endif