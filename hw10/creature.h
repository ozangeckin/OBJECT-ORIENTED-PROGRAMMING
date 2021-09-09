#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

namespace Game{

    class Creature
    {
        public:

            Creature();//no-parametre constructor
            Creature(int newStrength,int newHit);//two-parametre constructor
            Creature(int newType,int newStrength,int newHit);//three-parametre constructor

            void setStrength(int newStength);
            void setHitpoints(int newHit);
            void setType(int newType);

            int getDamage();
            int getType()const;
            int getStrength()const;
            int getHitpoints()const;
            string getSpecies()const;

        private:
        
            int type;
            int strength;
            int hitpoints;

    };

}
#endif