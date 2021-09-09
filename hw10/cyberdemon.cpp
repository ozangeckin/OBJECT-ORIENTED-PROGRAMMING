#include "cyberdemon.h"

using namespace std;

namespace Game{
    
    //no-parametre constructor
    Cyberdemon::Cyberdemon():Demon(){
        setType(1);
    }
    //two-parametre constructor
    Cyberdemon::Cyberdemon(int newStrength,int newHit):Demon(1,newStrength,newHit){
        
    }
    int Cyberdemon::getDamage(){
        int damage_=Demon::getDamage();
        cout << getSpecies() << " attacks for " <<damage_ << " points!" << endl;
        return damage_;

    }
    //return name of creature
    string Cyberdemon::getSpecies()const{
        if(getType()==1){
            return "CyberDemon";
        }
    }

}
