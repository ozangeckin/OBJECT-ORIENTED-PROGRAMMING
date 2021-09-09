#ifndef BOARD1D_H
#define BOARD1D_H
#include <iostream>
#include "abstractboard.h"
namespace OzanGtu{
	class Board_:public AbstractBoard{
		public:
			//constructor
			Board_();
			Board_(int row,int col);
			//Big three
			Board_& operator=(const Board_& other);
			Board_(const Board_& other);
			~Board_();

			void print()const;
			void reset();
			void readFromFile(string fileName);
			void writeToFile(string fileName);
			int isSolved();
			int& operator()(int x);
			void Move(char move);

		private:
			int *puzzle;

	};
}

#endif