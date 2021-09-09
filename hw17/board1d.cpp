#include <iostream>
#include <fstream>
#include<sstream>
#include "board1d.h"
using namespace std;
namespace OzanGtu{
	void Board_::print()const{
		int k=0;
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++)
			{
				if(puzzle[k]==-2)
				{
						cout<<"   ";
						continue;
						
				}				
			 	if(puzzle[k]<10)
				{
					cout<<"0";
				}
				cout<<puzzle[k]<<" ";
				k++;
			}			
					cout<<endl;
		}
	}
	
	void Board_::reset(){
		int q=1;
		int size=row*column;
		for(int i=0;i<size;i++){
			if(i==size-1){
				puzzle[i]=-2;
			}
			else{
			puzzle[i]=q;
			q++;
		}
		}
	}
	void Board_::readFromFile(string fileName){
		cout<<"implement readfromfile 1d array"<<endl;
		ifstream inputStream;
 		string num;
 		inputStream>>num;
 		int i=0;
		inputStream.open(fileName);
			while(!inputStream.eof())
			{
				inputStream>>num;
				if(num=="bb")
					{
					puzzle[i]=-2;
					}
				stringstream geek(num);

				geek>>puzzle[i];
				i++;
			}
	}
	void Board_::writeToFile(string fileName){
		ofstream outputStream;
		outputStream.open(fileName);
		int k=0;
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
				if(puzzle[k]<10&&puzzle[k]>=0)
 					outputStream<<"0";//save single-digit numbers with zeros.
 					if(puzzle[k]==-2)
 					{
 						outputStream<<"bb "; // bb don't get lost
 						continue;
 					}
 					outputStream<<puzzle[k]<<" ";// write numbers to file
 					k++;
 				}
 				outputStream<<endl;
 			}	
	}
	int Board_::isSolved(){
		int flag=0;
		for(int i=0;i<size-2;i++){
			if(puzzle[i+1]-puzzle[i]==1){
				flag++;
			}
		}
		if(flag==size){
			cout<<"Congratulations!!Puzzle is solved"<<endl;
			return 1;
		}else{
			cout<<"Puzzle is not solved"<<endl;
			return 0;
		}
	}
	int& Board_::operator()(int x){
		return puzzle[x];
	}
	void Board_::Move(char move){
		
	}
	Board_::Board_(){
		cout<<"Default 1d Board_ constructor"<<endl;
	}
	Board_::Board_(int row,int col):AbstractBoard(row,col){
		int x=row*col;
        puzzle=new int[x];
	
	}
	Board_& Board_::operator=(const Board_& other){
		this->row=other.row;
		this->column=other.column;
		this->size=other.size;
		this->x=other.x;
		this->y=other.y;
        int x=other.row*other.column;
		this->puzzle=new int[x];
		return *this;
	}
	Board_::Board_(const Board_& other){
		this->row=other.row;
		this->column=other.column;
		this->size=other.size;
		this->x=other.x;
		this->y=other.y;
        int x=other.row*other.column;
		this->puzzle=new int[x];
	}
	Board_::~Board_(){
		delete [] puzzle;
	}

}