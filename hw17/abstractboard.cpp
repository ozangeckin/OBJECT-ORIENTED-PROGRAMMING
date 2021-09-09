#include "abstractboard.h"
#include <iostream>
namespace OzanGtu{
	AbstractBoard::AbstractBoard(int row ,int col):row(row),column(col)
	{
		boardnumber=boardnumber+1;
	}
	void AbstractBoard::setSize(int x,int y)
	{
		row=x;
		column=y;
		size=x*y;
	}
	void AbstractBoard::setX(int x)
	{
			x=x;
	}
	void AbstractBoard::setY(int y)
	{
			y=y;
	}
	int AbstractBoard::numberofboards()
	{
 		return boardnumber;
	}
	char AbstractBoard::lastmove(char move)
	{
		numberOfMoves++;
		last_mov=move;
		return last_mov;
	}
	int AbstractBoard::numberOfMoves=0;
}