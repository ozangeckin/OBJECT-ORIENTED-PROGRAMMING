#include <iostream>
#include <memory>
#include "GTUContainer.h"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUVector.h"
#include "GTUVector.cpp"

using namespace OzanGTU;
using namespace std;
int main(){
    cout<<"----TEST SET---"<<endl;
    GTUSet<int> SetI(10,3,20);
    GTUSet<double>SetD(50,10,30);
    auto ptr=SetI.begin();
    cout<<"Integer Set is max_size "<<SetI.returnMax_size()<<endl;
    cout<<"Integer set is size "<<SetI.returnSize()<<endl;
    SetI.insert(5);
    SetI.insert(2);
    SetI.clear();
    cout<<"Clear function is working"<<endl;
   

    cout<<"is set empty?"<<endl;
    SetI.empty();

    cout<<"Double Set is max_size "<<SetD.returnMax_size()<<endl;
    cout<<"Double set is size "<<SetD.returnSize()<<endl;


  

    cout<<"----TEST VECTOR----"<<endl;
    GTUVector<int>Vector_(10,5,3);
    GTUVector<double>VectorD(8,6,10);
    cout<<"Integer Vector is max_size "<<Vector_.returnMax_size()<<endl;
    cout<<"Integer Vector is size "<<Vector_.returnSize()<<endl;
    Vector_.clear();
    cout<<"Double Vector is max_size"<<VectorD.returnMax_size()<<endl;
    cout<<"Double Vector is size"<<VectorD.returnSize()<<endl;


    return 0;
}