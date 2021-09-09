#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include"demon.h"

namespace Game{

    class Cyberdemon:public Demon{

        public:

            Cyberdemon();//no-parametre constructor
            Cyberdemon(int newStrength,int newHit);//two-parametre constructor
            int getDamage();
            string getSpecies()const;//return name of creatures
            
    };

}
#endif