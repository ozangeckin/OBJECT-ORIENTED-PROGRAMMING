#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H
#include <iostream>
#include <fstream>
using namespace std;
namespace OzanGtu
{
	class AbstractBoard
	{
	public:
		static int numberOfMoves;
		AbstractBoard(){}
		AbstractBoard(int row,int col);
		virtual void print()const=0;
		virtual void reset()=0;
		virtual void readFromFile(string fileName)=0;
		virtual void writeToFile(string fileName)=0;
		void setSize(int x,int y);
		virtual int isSolved()=0;
		virtual void Move(char move)=0;
		void setX(int x);
		void setY(int y);
		int numberofboards();  
		char lastmove(char move);
		protected:
			string fileName;
			fstream file;
			int row=0;
			int column=0;
			int x=0;
			int y=0;
			int location;//for space..
			char move;
			char last_mov='S';
			int boardnumber=0;
			int size;

	};

}
#endif