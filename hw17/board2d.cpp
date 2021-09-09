#include <iostream>
#include "board2d.h"
#include <cstdlib>
#include <ctime>
using namespace std;
namespace OzanGtu{
	void Board::print()const{
		for(int i=0 ; i<row ; i++)
			{
				for(int j=0 ; j<column ; j++)
				{
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
	void Board::reset(){
		for(int i = 0 ; i < row; i++)
			{
				for(int j=0; j< column;j++)
				{
					if((i*column+j)+1==row*column)
					{
						puzzle[i][j]=-2;
						x=i;
						y=j;
						continue;
					}
					puzzle[i][j]=(i*column+j)+1;
				}
			}
	}

	void Board::readFromFile(string fileName){
		ifstream inputStream;
 		string num;
		inputStream.open(fileName);
			for(int i=0;i<row&&!inputStream.eof();i++)
			{
				for(int j=0;j<column&&!inputStream.eof();j++)
				{	
					inputStream>>num;// reads numbers from file
					if(num=="bb")//bb to protect the place
					{
						puzzle[i][j] = -2;
						setX(i);
						setY(j);
					}
					else
					{
					puzzle[i][j] = ((int)num[0]-'0')*10 + (int)num[1]-'0';//are synchronized from the file, respectively
					}
				}
			}
	}
	void Board::writeToFile(string fileName){
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
	int Board::isSolved(){
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
	void Board::Move(char move){
	switch(move)//switch structure works according to the given command ..
		{	
		case 'D':
			if(x==row-1||puzzle[x+1][y]==0)//border controls and zero controls ..
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
	int& Board::operator()(int x,int y){
		return puzzle[x][y];
	}
	Board::Board(){
		cout<<"Default 2d board constructor"<<endl;
	}
	Board::Board(int row,int col):AbstractBoard(row,col){
		puzzle=new int*[row];
		for (int i=0; i<row; i++){
			puzzle[i]=new int[col];
		}
	
	}
	Board& Board::operator=(const Board& other){
		this->row=other.row;
		this->column=other.column;
		this->size=other.size;
		this->x=other.x;
		this->y=other.y;
		this->puzzle=new int*[row];
		for(int i=0; i<row;i++){
			this->puzzle[i]=new int[column];
		}
		return *this;
	}
	Board::Board(const Board& other){
		this->row=other.row;
		this->column=other.column;
		this->size=other.size;
		this->x=other.x;
		this->y=other.y;
		this->puzzle=new int*[row];
		for(int i=0; i<row;i++){
			this->puzzle[i]=new int[column];
		}
	}
	Board::~Board(){
		delete [] puzzle;
	}

}