#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;
//classes used in the program
class Organism;
class Ant;
class Doodlebug;
//definiton world class
class  World{
    public:
        World();
        ~World();
        Organism* getPosition(int row_,int column_);
        void setPosition(int row_,int column_,Organism *org);
        void print();
        void game();
        int getDoodCount();
        int getAntCount();
    private:
        //I used friend to use world object in Organism ant and doodlebug classes
        friend class Organism;
        friend class Ant;
        friend class Doodlebug;

        Organism* area[20][20];
        int doodCount=0;
        int antCount=0;

};
//definition world class
class Organism{
    //I used friend to use organism object in World class
    friend class World;
    public:
        Organism();
        Organism(World *wrld_ ,int row_,int column_);
        ~Organism();

        virtual void breed()=0;
        virtual void moved()=0;
        virtual bool starve()=0;
        virtual string getName()=0;

    protected:
        bool move;
        World *worldd;
        int row,column;
        int breedd;

}; 
//default constructor World class
World::World(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            area[i][j]=NULL;
        }
    }
}
//destructor World class
World::~World()
{
     for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(area[i][j]!=NULL){
                delete(area[i][j]);
            }
        }
    } 
}
//return current position
Organism* World::getPosition(int row_,int column_){
    if((row_<20) && (column_<20) && (row_>=0) && (column_>=0)){
        return area[row_][column_];
    }else{
        cout<<"Error:Inverse position"<<endl;
        return NULL;
    }

}
//To set current position
void World::setPosition(int row_,int column_,Organism *org){
    if((row_<20) && (column_<20) && (row_>=0) && (column_>=0)){
            area[row_][column_]=org;
    }
}
//To display area
void World::print(){
    antCount=0;
    doodCount=0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(area[i][j]==NULL){
                cout<<" . ";
            
            }else if(area[i][j]->getName()=="ant"){
                antCount++;
                cout<<" o ";
            }
            else{
                doodCount++;
                cout<<" X ";
            }
            }
            cout<<endl;
        }
    }
//return Ant numbers
int World::getAntCount(){
    return antCount;
}
//return Doodlebug numbers
int World::getDoodCount(){
    return doodCount;
}
//To game
void World::game(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(area[i][j]!=NULL){
                area[i][j]->move=false;
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if((area[i][j]!=NULL)&&(area[i][j]->getName()=="doodlebug")){

                if(area[i][j]->move==false){
                    area[i][j]->move=true;
                    area[i][j]->moved();

                }
            }
        }
    }
    for(int i=0 ;i<20;i++){
        for(int j=0;j<20;j++){
            if((area[i][j]!=NULL)&&(area[i][j]->getName()=="ant")){
                if(area[i][j]->move==false){
                    area[i][j]->move=true;
                    area[i][j]->moved();
                }
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if((area[i][j]!=NULL)&&(area[i][j]->getName()=="doodlebug")){
                if(area[i][j]->starve()){
                    delete(area[i][j]);
                    area[i][j]=NULL;
                }
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if((area[i][j]!=NULL)&&(area[i][j]->move==true)){
                area[i][j]->breed();
            }
        }
    }
}

//default constructor Organism class
Organism::Organism(){
    breedd=0;
    worldd=NULL;
    move=false;
    row=0;
    column=0;
}
//three parametre constructor Organism class
Organism::Organism(World *wrld_,int row_,int column_){
    this->worldd=wrld_;
    move=false;
    breedd=0;
    this->row=row_;
    this->column=column_;
    wrld_->setPosition(row_,column_,this);
}
//destructor Organism
Organism::~Organism(){

}
//definiton Ant class extends Organism class
class Ant:public Organism{
    friend class World;
    public:
    Ant();
    Ant(World *world_,int rw_,int clumn_);

    void breed();
    void moved();
    string getName();
    bool starve();

};
//default constructor
Ant::Ant():Organism(){

}
//three parametre constructor Ant
Ant::Ant(World *world_,int rw_,int clumn_):Organism(world_,rw_,clumn_){

}
//To ensure the movement of ants
void Ant::moved(){
    int way= rand()%4;
    if(way==0){
        if((column>0)&&(worldd->getPosition(row,column-1)==NULL)){
            worldd->setPosition(row,column-1,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            column--;
        }
    }
    else if(way==1){
        if((column<19)&&(worldd->getPosition(row,column+1)==NULL)){
            worldd->setPosition(row,column+1,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            column++;
        }

    }else if(way==2){
        if((row<0) && (worldd->getPosition(row-1,column)==NULL)){
            worldd->setPosition(row-1,column,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            row--;
        }
    }else{
        if((row<19)&& (worldd->getPosition(row+1,column)==NULL)){
            worldd->setPosition(row+1,column,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            row++;
        }

    }

}
//return obje name
string Ant::getName(){
    return "ant";
}
//to breed ants
void Ant::breed(){
    breedd++;
    if(breedd==3){
        breedd=0; 
        if((column>0)&&(worldd->getPosition(row,column-1)==NULL)){
            Ant *breedAnt=new Ant(worldd,row,column-1);
        }else if((column<19)&&(worldd->getPosition(row,column+1)==NULL)){
            Ant *breedAnt=new Ant(worldd,row,column+1);
        }else if((row>0)&&(worldd->getPosition(row-1,column)==NULL)){
            Ant *breedAnt=new Ant(worldd,row-1,column);
        }else if((row<19)&&(worldd->getPosition(row+1,column)==NULL)){
            Ant *breedAnt=new Ant(worldd,row+1,column);
        }  
    }
}
//to dead ants
bool Ant::starve(){
    return false;
}
//definiton Doodlebug class extends Organism class
class Doodlebug:public Organism{
    friend class World;
    public:
        Doodlebug();
        Doodlebug(World *world_,int row_,int column_);
        void breed();
        void moved();
        string getName();
        bool starve();
    private:
        int starv;
};
//default constructor
Doodlebug::Doodlebug():Organism(){
    starv=0;
}
//three parametre constructor
Doodlebug::Doodlebug(World *world_,int row_,int column_):Organism(world_,row_,column_){
    starv=0;
}
//To ensure the movement of Doodlebug
void Doodlebug::moved(){
    if((column>0) && (worldd->getPosition(row,column-1) !=NULL)&&(worldd->getPosition(row,column-1)->getName()=="ant")){
        delete(worldd->area[row][column-1]);
        worldd->setPosition(row,column-1,this);
        worldd->setPosition(row,column,NULL);
        starv=0;
        column--;
        return;
    }
    else if((column<19)&&(worldd->getPosition(row,column+1)!=NULL)&&(worldd->getPosition(row,column+1)->getName()=="ant")){
        delete(worldd->area[row][column+1]);
        worldd->setPosition(row,column+1,this);
        worldd->setPosition(row,column,NULL);
        starv=0;
        column++;
        return;
    }else if((row>0)&&(worldd->getPosition(row-1,column)!=NULL)&&(worldd->getPosition(row-1,column)->getName()=="ant")){
        delete(worldd->area[row-1][column]);
        worldd->setPosition(row-1,column,this);
        worldd->setPosition(row,column,NULL);
        starv=0;
        row--;
        return;
    }else if((row<19)&&(worldd->getPosition(row+1,column)!=NULL)&&(worldd->getPosition(row+1,column)->getName()=="ant")){
        delete(worldd->area[row+1][column]);
        worldd->setPosition(row+1,column,this);
        worldd->setPosition(row,column,NULL);
        starv=0;
        row++;
        return;
    }

    int way=rand()%4;
       if(way==0){
        if((column>0)&&(worldd->getPosition(row,column-1)==NULL)){
            worldd->setPosition(row,column-1,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            column--;
        }
    }
    else if(way==1){
        if((column<19)&&(worldd->getPosition(row,column+1)==NULL)){
            worldd->setPosition(row,column+1,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            column++;
        }

    }else if(way==2){
        if((row<0) && (worldd->getPosition(row-1,column)==NULL)){
            worldd->setPosition(row-1,column,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            row--;
        }
    }else{
        if((row<19)&& (worldd->getPosition(row+1,column)==NULL)){
            worldd->setPosition(row+1,column,worldd->getPosition(row,column));
            worldd->setPosition(row,column,NULL);
            row++;
        }

    }
   starv++;     
}
//retur class name 
string Doodlebug::getName(){
    return "doodlebug";
}
//to breed Doodlebug
void Doodlebug::breed(){
    breedd++;
    if(breedd==8){
        breedd=0;
        if((column>0)&&(worldd->getPosition(row,column-1)==NULL)){
            Doodlebug *breedDood =new Doodlebug(worldd,row,column-1);
        }else if((column<19)&&(worldd->getPosition(row,column+1)==NULL)){
            Doodlebug *breedDood=new Doodlebug(worldd,row,column+1);
        }else if((row>0)&&(worldd->getPosition(row-1,column)==NULL)){
            Doodlebug *breedDood=new Doodlebug(worldd,row-1,column);
        }else{
            Doodlebug *breedDood=new Doodlebug(worldd,row+1,column);
        }   
    }

}
//to starve doodlebug
bool Doodlebug::starve(){
    if(starv >3){
        return true;
    }else{
        return false;
    }
}
//main function
int main(){
    string input;//user input "Enter"
    srand(time(NULL));//to random number
    World obje;//create World obje
    int antCount=0;//Ant count
    int doodCount=0;//Doodlebug count
    int round=0;//round counter

    while(antCount<100){//create Ant
        int row =rand()%20;
        int column=rand()%20;
        if(obje.getPosition(row,column)==NULL){
            antCount++;
            Ant *a=new Ant(&obje,row,column);
        }
    }
    while(doodCount<5){//create Doodlebug
        int row=rand()%20;
        int column=rand()%20;
        if(obje.getPosition(row,column)==NULL){
            doodCount++;
            Doodlebug *d =new Doodlebug(&obje,row,column);
        }
    }
    do{
        obje.print();//call obje print function
        round++;//round counter++
        obje.game();//call obje game function
        if(obje.getDoodCount()<1){//to check game finish
            cout<<"Game finish because all Doodlebug's dead\n"<<endl;
            exit(1);
        }
        if(obje.getAntCount()<1){//to check game finish
            cout<<"Game finish because all Ant's dead\n"<<endl;
            exit(1);
        }
        cout<<endl<<"Press enter for next round ,current round "<<round<<" (Press 'Q' or 'q' for exit)"<<endl;//to exit game
        getline(cin,input);
    }while(true && (input!="Q")&&(input!="q"));
}