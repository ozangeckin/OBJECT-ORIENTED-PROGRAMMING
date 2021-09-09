#include "human.h"

namespace Game{

    //no-parametre constructor
    Human::Human():Creature(){
        setType(0);
    }
    //two-parametre constructor
    Human::Human(int newStrength,int newHit):Creature(0,newStrength,newHit){

    }
    int Human::getDamage(){
        int  damage_=Creature::getDamage();
        cout << getSpecies() << " attacks for " <<damage_ << " points!" << endl;
        return damage_;    
    }
    //return name of creature
    string Human::getSpecies() const
    {
        if(getType()==0){
            return "Human";
        }
    }
    
}