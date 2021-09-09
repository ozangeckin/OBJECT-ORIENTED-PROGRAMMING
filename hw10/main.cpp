#include "creature.h"
#include "demon.h"
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"

//definition namespace
using namespace Game;
//Program begins with a main 
int main()
{
   //for generate random value 
    srand(time(NULL));
    int damage=0,round=1;
   //objects to be used for testing are defined
    Creature Cr;
    Human h;
    Elf e;
    Cyberdemon c;
    Balrog b;
    Human h2(10, 20);
    Elf e2(30, 40);
    Cyberdemon c2(50, 60);
    Balrog b2(70, 80);

   //check constructor
    cout << "Default Creature "<<Cr.getSpecies()<<" : strength "<<Cr.getStrength()<< " hitpoint " <<Cr.getHitpoints()<<endl;
    cout << "Default "<<h.getSpecies()<<" : strength " << h.getStrength()<< " hitpoint " << h.getHitpoints() << endl;
    cout << "Default "<<e.getSpecies()<<" : strength " << e.getStrength()<< " hitpoint " << e.getHitpoints() << endl;
    cout << "Default "<<c.getSpecies()<<" : strength " << c.getStrength()<< " hitpoint " << c.getHitpoints() << endl;
    cout << "Default "<<b.getSpecies()<<" : strength " << b.getStrength()<< " hitpoint " << b.getHitpoints() << endl;
   
    cout << "\nTwo parametre "<<h2.getSpecies()<<" : strength " << h2.getStrength()<< " hitpoint " << h2.getHitpoints() << endl;
    cout << "Two parametre "<<e2.getSpecies()<<" : strength " << e2.getStrength()<< " hitpoint " << e2.getHitpoints() << endl;
    cout << "Two parametre "<<c2.getSpecies()<<" : strength " << c2.getStrength()<< " hitpoint " << c2.getHitpoints() << endl;
    cout << "Two parametre "<<b2.getSpecies()<<" : strength " << b2.getStrength()<< " hitpoint " << b2.getHitpoints() << endl;

    cout<<"\n***FIGHT***"<<endl;
    while(1){
        cout<<"\nRound = "<<round<<endl;
        cout<<"\nCyberdemon attacks Human"<<endl;
        cout<<"Human hitpoints "<<h.getHitpoints()<<endl;
        cout<<"Cyberdemon hitpoints "<<c.getHitpoints()<<endl;
        damage=h.getHitpoints()-c.getDamage();
        h.setHitpoints(damage);
        cout<<"Human hitpoints after attack "<<h.getHitpoints()<<endl;
        if(h.getHitpoints()<1){
        cout<<h.getSpecies()<<" died"<<endl;
        break;
        } 
        else{
            cout<<h.getSpecies()<<" lives"<<endl;
            cout<<"Human attacks Cyberdemon"<<endl;
            cout<<"Human hitpoints "<<h.getHitpoints()<<endl;
            cout<<"Cyberdemon hitpoints "<<c.getHitpoints()<<endl;
            damage=c.getHitpoints()-h.getDamage();
            c.setHitpoints(damage);
            cout<<"Cyberdemon hitpoints after attack "<<c.getHitpoints()<<endl;
        }   
        if (c.getHitpoints()<1){
            cout<<c.getSpecies()<<" died"<<endl;
            break;
            }else{
                cout<<c.getSpecies()<<" lives";
            }
            round++;
    }
    cout<<"************"<<endl;
//check your special abilities and random powers produced
    cout << "\nTest of default " << h.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h.getDamage();
        cout << "Total Damage = " << damage << endl;
    }
    cout << endl;
   
    cout << "Test of default " << e.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
       int damage = e.getDamage();
       cout << "Total Damage = " << damage << endl;
    }
    cout << endl;
   
    cout << "Test of default " << c.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
        int damage = c.getDamage();
        cout << "Total Damage = " << damage << endl;
    }
    cout << endl;
    cout << "Test of default " << b.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
       int damage = b.getDamage();
       cout << "Total Damage = " << damage << endl;
    }
    cout << endl;

    cout << "\nTest of Two parametre " << h2.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h2.getDamage();
        cout << "Total Damage = " << damage << endl;
    }
    cout << endl;
   
    cout << "Test of Two parametre " << e2.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
       int damage = e2.getDamage();
       cout << "Total Damage = " << damage << endl;
    }
    cout << endl;
   
    cout << "Test of Two parametre " << c2.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
        int damage = c2.getDamage();
        cout << "Total Damage = " << damage << endl;
    }
    cout << endl;
    cout << "Test of Two parametre " << b2.getSpecies() << " damage: \n" << endl;
    for (int i = 0; i < 10; i++) {
        int damage = b2.getDamage();
        cout << "Total Damage = " << damage << endl;
    }
    cout << endl;

}