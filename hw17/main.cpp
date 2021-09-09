#include <iostream>
#include "abstractboard.h"
#include "board2d.h"
#include "board1d.h"
#include <vector>
#include "vec.h"
using namespace std;

bool Global(vector<OzanGtu::AbstractBoard*> ptr)
{
	for(int i=0;i<ptr.size();i++){
		if(ptr[i]==ptr[i+1]){
			return 1;
		}
	}
	return 0;
}

int main(){
	cout<<"!DRİVER!"<<endl;
	cout<<"Constructors are working"<<endl;
	OzanGtu::AbstractBoard* x;
	OzanGtu::AbstractBoard* y;
	OzanGtu::AbstractBoard* z;
	OzanGtu::Board twoD(3,3);//2D array constructor
	OzanGtu::Board_ oneD(3,3);//1D array constructor
	OzanGtu::BoardV vec(3,3);// vector constructor
	
	vector<OzanGtu::AbstractBoard*> ptr;
	ptr.push_back(x);

	cout<<"\n2DARRAY"<<endl;// Test functions for 2D array ..
	twoD.readFromFile("init.txt");
	cout<<"readFromFile 2DARRAY"<<endl;
	twoD.print();
	twoD.writeToFile("output1.txt");
	twoD.reset();
	cout<<"\nReset 2DARRAY"<<endl;
	twoD.print();
	twoD.Move('L');
	cout<<"\nLeft Move in 2DARRAY"<<endl;
	twoD.print();
	cout<<endl;
	cout<<"1DARRAY Board Number"<<twoD.numberofboards();
	cout<<endl;

	cout<<"1DARRAY"<<endl;// Test functions for 1D array ..
	oneD.readFromFile("init.txt");
	oneD.print();
	oneD.writeToFile("output2.txt");
	cout<<endl;
	oneD.reset();
	cout<<"Reset 1DARRAY"<<endl;
	oneD.print();
	oneD.isSolved();
	cout<<endl;
	cout<<"2DARRAY Board Number"<<oneD.numberofboards();
	cout<<endl;

	
	cout<<"VECTOR"<<endl;// Test functions for Vector ..
	
	vec.reset();
	vec.isSolved();
	cout<<"Reset VECTOR"<<endl;
	cout<<"readFromFile VECTOR"<<endl;
	vec.readFromFile("init.txt");
	vec.print();
	vec.writeToFile("output3.txt");
	vec.isSolved();
	vec.Move('L');
	cout<<endl;
	cout<<"VECTOR Board Number"<<vec.numberofboards()<<endl;
	cout<<endl;

	cout<<"Sum Board Number"<<vec.numberofboards()+oneD.numberofboards()+twoD.numberofboards()<<endl;
	// assignment operations for global function
	x=&twoD;
	y=&oneD;
	z=&vec;

	ptr.push_back(x);
	ptr.push_back(y);
	ptr.push_back(z);

	
	
}