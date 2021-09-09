#include"balrog.h"

namespace Game{

    //no-parametre constructor
    Balrog::Balrog():Demon(){
        setType(2);
    }
    //two-parametre constructor
    Balrog::Balrog(int newStregth,int newHit):Demon(2,newStregth,newHit){

    }
    //redefined getDamagede function
    //Balrogs are very fast, so they get to attack twice.
    int Balrog::getDamage(){
        int damage_=Demon::getDamage();
        cout << getSpecies() << " attacks for " <<damage_ << " points!" << endl;
        int rDamage=((rand()%Balrog::getStrength())+1);
        cout << "Balrog's special attack damage " << rDamage << " damage! " << endl;
        damage_=(damage_+rDamage);
        return damage_;
    }
    //return name of creature
    string Balrog::getSpecies() const
    {
        if(getType()==2){
        return "Balrog";
        }
    }
    
}