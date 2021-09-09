#include "elf.h"
 
namespace Game{
    //no-parametre constructor
    Elf::Elf():Creature(){
        setType(3);
    }
    //two-parametre constructor
    Elf::Elf(int newStrength,int newHit):Creature(3,newStrength,newHit){

    }
    //redefined getDamagede function
    //With a 10% chance elf inflict a magical attack that doubles the normal amount of damage.
    int Elf::getDamage(){
        int  damage_=Creature::getDamage();
        cout << getSpecies() << " attacks for " <<damage_ << " points!" << endl;
        int q = (rand()%10+1);
        if(q<=5){
            cout << " Special attack power " << damage_ << " additional damage(damage*2)! " << endl;
            damage_ = (damage_ * 2);  
        }
        return damage_;
    }
    //return name of creature
    string Elf::getSpecies() const
    {
        if(getType()==3){
            return "Elf";
        }
    }
}
