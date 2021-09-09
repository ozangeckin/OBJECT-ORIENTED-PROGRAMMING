#include"creature.h"

namespace Game{

    //no-parametre constructor
    Creature::Creature(){
        strength=10;
        hitpoints=10;
        type=0;
        srand(time(NULL));
    }
    //two-parametre constructor
    Creature::Creature(int newStrength,int newHit){
        strength=newStrength;
        hitpoints=newHit;
        srand(time(NULL));
    }
    //three-parametre constructor
    Creature::Creature(int newType,int newStrength,int newHit){
        type=newType;
        strength=newStrength;
        hitpoints=newHit;
        srand(time(NULL));
    }
    //return damage
    //Every creature inflicts damage that is a random number r, where 0 < r <= strength
    int Creature::getDamage()
    {
        int damage=0;
        damage = (rand() % strength) + 1;    
        return damage;
    }
    //return strength of creature
    int Creature::getStrength() const {
    	return strength;
    }
    //return hitpoints of creature
    int Creature::getHitpoints() const {
    	return hitpoints;
    }
    //return type of creature
    int Creature::getType()const{
        return type;
    }
    //return Species type of creature
    string Creature::getSpecies()const{
        if(type==0){
            return "Human";
        }
        return "unknown";
    }
    //set hitpoints
    void Creature::setHitpoints(int newHit){
        hitpoints=newHit;
    }//set strength
    void Creature::setStrength(int newStrength){
        strength=newStrength;
    }
    //set type
    void Creature::setType(int newType){
        type=newType;
    }

}