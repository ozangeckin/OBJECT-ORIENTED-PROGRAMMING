#ifndef VEC_H
#define VEC_H
#include <iostream>
#include "abstractboard.h"
#include <vector>
namespace OzanGtu{
	class BoardV:public AbstractBoard{
		public:
			//constructor
			BoardV();
			BoardV(int row,int col);
			void print()const;
			void reset();
			void readFromFile(string fileName);
			void writeToFile(string fileName);
			int isSolved();
			int& operator()(int x,int y);
			void Move(char move);

		private:
			vector<vector<int>> puzzle;

	};
}

#endif