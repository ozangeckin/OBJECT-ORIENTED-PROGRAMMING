#include <iostream>
#include "vec.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
namespace OzanGtu{
	void BoardV::print()const{
       for (int i = 0; i < puzzle.size(); i++) { 
        for (int j = 0; j < puzzle[i].size(); j++) {
        		if(puzzle[i][j] == -2)
					{
						cout<<"   ";
						continue;
					}
				if(puzzle[i][j]<10)
					{
					cout<<"0";
					}
				cout<<puzzle[i][j]<<" ";
			
				}
			cout<<endl;
			}	
	}   
	void BoardV::reset(){
        int q=1;
		for(int i=0; i< row; i++){
            vector<int> k;
            for (int j=0; j<column;j++){
                if(i==row-1 && j==column-1) //for the last position we place a 0
                {
                    k.push_back(-2);
                }
                else{
                    k.push_back(q); //fill interger values 
                }
                q++;
            }
            puzzle.push_back(k);
        }
	}
	void BoardV::readFromFile(string fileName){
		ifstream inputStream;
 		string num;
		inputStream.open(fileName);
			for(int i=0;i<row&&!inputStream.eof();i++)
			{
				vector<int> k;
				for(int j=0;j<column&&!inputStream.eof();j++)
				{	
					inputStream>>num;
					
					if(num=="bb")
					{
					k.push_back(-2);
						setX(i);
						setY(j);
					}
					else
					{
					k.push_back ( ((int)num[0]-'0')*10 + (int)num[1]-'0');
					}
				}
				puzzle.push_back(k);
			}
			
	}
	void BoardV::writeToFile(string fileName){
       ofstream outputStream;
		outputStream.open(fileName);
		for(int i=0 ; i<row;i++)
		{
			for(int j=0 ; j<column;j++)
			{
				if(puzzle[i][j]<10&&puzzle[i][j]>=0)
 					outputStream<<"0";
 					if(puzzle[i][j]==-2)
 					{
 						outputStream<<"bb "; 
 						continue;
 					}
 					outputStream<<puzzle[i][j]<<" ";
 				}
 				outputStream<<endl;
 			}	
	}
    
	int BoardV::isSolved(){
		for(int i = 0 ; i < row ; i++)
		{
			for(int j = 0 ; j < column ; j++)
			{
				if(puzzle[i][j]!=(i*row)+j+1)
				cout<<"Puzzle is not solved"<<endl;
				return 0;
			}
		}
		cout<<"Congratulations!!Puzzle is solved"<<endl;
		return 1;	
	}
	void BoardV::Move(char move){
			switch(move)
		{	
		case 'D':
			if(x==row-1||puzzle[x+1][y]==0)
				break;
				puzzle[x][y]=puzzle[x+1][y];
 				puzzle[x+1][y]=-2;
 				x=x+1;
 				break;
		case 'U':
			if(x==0||puzzle[x-1][y]==0)
				break;
 				puzzle[x][y]=puzzle[x-1][y];
 				puzzle[x-1][y]=-2;
 				x=x-1;
 				break;
		case 'L':
			if(y==0||puzzle[x][y-1]==0)
				break;
 				puzzle[x][y]=puzzle[x][y-1];
 				puzzle[x][y-1]=-2;
 				y=y-1;
 				break;
		case 'R':
			if(y==column-1||puzzle[x][y+1]==0)
				break;
 				puzzle[x][y]=puzzle[x][y+1];
 				puzzle[x][y+1]=-2;
 				y=y+1;
 				break;
 		case 'S':
			for(int i = 0 ; i < size ; i++)//you want to step up because you will continue until ..
			{
				int random = rand() % (3-0+1);//For random mixing ..
				switch(random)
				{
					case 0:
						if(x==row-1||puzzle[x+1][y]==0)//border controls ..
							break;
							puzzle[x][y]=puzzle[x+1][y];
							puzzle[x+1][y]=-2;
							x=x+1;
							break;
					case 1:
						if(x==0||puzzle[x-1][y]==0)
							break;
							puzzle[x][y]=puzzle[x-1][y];
							puzzle[x-1][y]=-2;
							x=x-1;
							break;
					case 2:
						if(y==0||puzzle[x][y-1]==0)
							break;
							puzzle[x][y]=puzzle[x][y-1];
							puzzle[x][y-1]=-2;
							y=y-1;
							break;
					case 3:
						if(y==column-1||puzzle[x][y+1]==0)
							break;
							puzzle[x][y]=puzzle[x][y+1];
							puzzle[x][y+1]=-2;
							y=y+1;
							break;
					}		
				}
				break;	
			}
		
	}
	int& BoardV::operator()(int x,int y){
		return puzzle[x][y];
	}
	BoardV::BoardV(){
		cout<<"Default 2d BoardV constructor"<<endl;
	}
	BoardV::BoardV(int row,int col):AbstractBoard(row,col){
        int k=1; 
        this->row=row;
        this->column=col;
	}
}