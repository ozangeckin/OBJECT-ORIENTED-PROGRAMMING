#ifndef BOARD2D_H
#define BOARD2D_H
#include <iostream>
#include "abstractboard.h"
namespace OzanGtu{
	class Board:public AbstractBoard{
		public:
			//constructor
			Board();
			Board(int row,int col);
			//Big three
			Board& operator=(const Board& other);
			Board(const Board& other);
			~Board();

			void print()const;
			void reset();
			void readFromFile(string fileName);
			void writeToFile(string fileName);
			int isSolved();
			int& operator()(int x,int y);
			void Move(char move);

		private:
			int **puzzle;

	};
}

#endif