#include"demon.h"

namespace Game{
    //no-parametre constructor
    Demon::Demon():Creature(){

    }
    //two-parametre constructor
    Demon::Demon(int newType,int newStrength,int newHit):Creature(newType,newStrength,newHit){

    }
    //redefined getDamagede function
    //Demons have a 5% chance of inflicting a demonic attack which is an additional 50 damage points.
    int Demon::getDamage(){

        int damage_=Creature::getDamage();
        if((rand()%100)<5){
            cout << "Demon special attack ("<<damage_<<") +50 additional damage points ! " << endl;
            damage_=damage_+50;
            }   
        return damage_;    
    }
    //return name of creature
    string Demon::getSpecies() const
    {
        if(getType()==1||getType()==2){
            return "Demon";
        }
    }
}