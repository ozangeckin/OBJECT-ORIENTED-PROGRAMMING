#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class NPuzzle
{
	private:
	class Board
	{
		private:
		int puzzle[9][9];
		
		public:
		int x,y,size,row,column,row_bb,b_flag=0;
		string num;
		void reset()
		{
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
		void print()
		{
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
		void readFromFile(char* fileName)
		{
			int flag=0,row_bb=1,size_=0;
			string num;
			if(b_flag==1)//if started with argv..
			{
				ifstream inputStream;//to read the file
				inputStream.open(fileName);
				for(int i=0;i<9&&!inputStream.eof();i++)
				{
					for(int j=0;j<9&&!inputStream.eof();j++)
					{	
						if(flag==1)
							row_bb++;//to find row and column
						inputStream>>num;//reads number from file
						size_++;
						if(num=="bb")//to protect the place where th bb
						{
							flag=1;
							puzzle[i][j] = -2;
							x=i;
							y=j;
						}
						else
						{
							puzzle[i][j] = ((int)num[0]-'0')*10 + (int)num[1]-'0';//sýrasýyla dosyadan eþitlenir
						}
					}
				}
				size=--size_;
				column=--row_bb;
				row=size/column;
			}
			else//called later in the game (row and column are known)
			{
				ifstream inputStream;
				inputStream.open(fileName);
				for(int i=0;i<row&&!inputStream.eof();i++)
				{
					for(int j=0;j<column&&!inputStream.eof();j++)
					{	
						inputStream>>num;//reads number from file
						if(num=="bb")//to protect the place where the bb 
						{
							puzzle[i][j] = -2;
							x=i;
							y=j;
						}
						else
						{
							puzzle[i][j] = ((int)num[0]-'0')*10 + (int)num[1]-'0';//sýrasýyla dosyadan eþitlenir
						}
					}
				}
			}
			b_flag=0;//indicates that you have entered.
				
		}
		void writeToFile(char* fileName)
		{
			ofstream outputStream;
			outputStream.open(fileName);
			for(int i=0 ; i<row;i++)
			{
				for(int j=0 ; j<column;j++)
				{
					if(puzzle[i][j]<10&&puzzle[i][j]>=0)
						outputStream<<"0";//to save single-digit numbers with 0
					if(puzzle[i][j]==-2)
					{
						outputStream<<"bb "; // bb don't get lost.
						continue;
					}
					outputStream<<puzzle[i][j]<<" ";//writes numbers to file
				}
				outputStream<<endl;
			}	
		}
		void setSize(int row_,int column_)//this function sets the row column set value that is private.
		{
			row = row_;
			column = column_;
			size=row*column;
			reset();
		}
		void move(char mov)
		{
			switch(mov)//switch structure works according to given command
			{	
			case 'D':
				if(x==row-1||puzzle[x+1][y]==0)//controls limits and zeros.
					break;
				puzzle[x][y]=puzzle[x+1][y];
				puzzle[x+1][y]=-2;
				x=x+1;
				break;
			case 'U':
				if(x==0||puzzle[x-1][y]==0)//controls limits and zeros.
					break;
				puzzle[x][y]=puzzle[x-1][y];
				puzzle[x-1][y]=-2;
				x=x-1;
				break;
			case 'L':
				if(y==0||puzzle[x][y-1]==0)//controls limits and zeros.
					break;
				puzzle[x][y]=puzzle[x][y-1];
				puzzle[x][y-1]=-2;
				y=y-1;
				break;
			case 'R':
				if(y==column-1||puzzle[x][y+1]==0)//controls limits and zeros.
					break;
				puzzle[x][y]=puzzle[x][y+1];
				puzzle[x][y+1]=-2;
				y=y+1;
				break;
			}	
		}
		int isSolved()
		{
			for(int i = 0 ; i < row ; i++)
			{
				for(int j = 0 ; j < row ; j++)
				{
					if(puzzle[i][j]==-2&&i==row-1&&j==column-1)
					return 1;
					if(puzzle[i][j]!=(i*row)+j+1)
					return 0;
				}
			}
		}
		int return_inversion_number()//used invers number for solvable test.
		{
			int inversion=0;
			int *array = new int[row*row-1];
			int n = 0;
			for(int i = 0 ; i < row ; i++)
			{
				for(int j = 0 ; j < row ; j++)
				{
					if(puzzle[i][j]!=row*row)
					{
						array[n] = puzzle[i][j];
						n++;
					}
				}	
			}
	
			for(int i = 0 ; i < n ; i++)
			{
				for (int j=i+1 ; j < n ; j++)
				{
			
					if(array[i]>array[j])
					inversion++;
				}
			}

			return inversion;
		}
		void solvePuzzle()//more intelligent..
		{
			int select;
			if(x>row/2)//'bb' is staying somewhere further down
			{
				if(y>column/2)//'bb'is staying somewhere further right
				{
					if(puzzle[x][y-1]>puzzle[x][y+1])//if it is larger than the right on the left, there is a problem.
					{
						select=0;	
					}
					else//if this is not the case, it will be right to move to the right
					{
						select=3;
					}
					if(puzzle[x-1][y]>puzzle[x+1][y])//If the above is greater than the following, there is problem
					{
						select=2;
					}
					else//if it doesn't, it would be better to go down
					{
						select=0;
					}
				}
				else//'bb' is a place to the left more left. It would make sense to go to the right ..
				{
					select=3;
				}
		}
			if(x<row/2)//'bb'is staying somewhere higher up
			{
				if(y>column/2)//'bb'is staying somewhere further right
				{
					if(puzzle[x][y-1]>puzzle[x][y+1])//it is a problem as mentioned above but it should move down because it is above
					{
						select=0;
					}
					else//if this is not the case, it would be appropriate to move to the right
					{
						select=3;
					}
					if(puzzle[x-1][y]>puzzle[x+1][y])//If the above is greater than the following, there is a problem
					{
						select=0;
					}
					else//if it does not, it would be appropriate to go to the right
					{
						select=3;
					}
				}
				else//'bb' is a place to the left more left. It would make sense to go to the right ..
				{
					select=3;
				}
			}
			if(select == 0)
			{
				move('D');
				cout<<"Your intelligent move is D\n";
			}
			else if(select == 2)
			{
				move('L');
				cout<<"Your intelligent move is L\n";
			}
			else if(select == 3)
			{
				move('R');
				cout<<"Your intelligent move is R\n";
			}
		}
			
		
	};
	public:
	Board board_;
	void print()
	{
		board_.print();
	}
	void readFromFile(char* filename)
	{
		board_.readFromFile(filename);
	}
	void writeToFile(char* filename)
	{
		board_.writeToFile(filename);
	}
	void reset()
	{
		board_.reset();
	}
	void setsize(int row,int column)
	{
		board_.setSize(row,column);
	}
	void moveRandom()
	{
		int random = rand() % (3-0+1);//for random mixing
		switch(random)
		{
			case 0:
				board_.move('R');
				break;
			case 1:
				board_.move('L');
				break;
			case 2:
				board_.move('U');
				break;
			case 3:
				board_.move('D');
				break;
		}		
	}
	void shuffle()
	{
		for(int i = 0 ; i < board_.size*board_.size ; i++)//for random mixing
		{
			int random = rand() % (3-0+1);//for random mixing
			switch(random)
			{
				case 0:
					board_.move('R');	
					break;
				case 1:
					board_.move('L');	
					break;
				case 2:
					board_.move('U');
					break;
				case 3:
					board_.move('D');
					break;
			}		
		}
	}
	void moveIntelligent()
	{
		int select;
		if (board_.x == board_.row-2 && board_.y == board_.column-1)
		{
			select = 0;
					
		}
		else if (board_.x == board_.row-1 && board_.y == board_.column-2)
		{
			select = 3;
		}
		else if (board_.y == board_.column-1 )
		{
			select = 0;
		}
		else if (board_.x == board_.row-1)
		{
			select =3;
		}
		else if (board_.x == board_.row-2 && board_.y ==board_.row-2)
		{
			select = 0;
		}
		else if(board_.x == board_.row-3 && board_.y == board_.row-2)
		{
			select = 3;				
		}
		switch(select)
		{
		case 0:
			cout<<"Your intelligent move is R\n";
			board_.move('R');	
			break;
		case 1:
			cout<<"Your intelligent move is L\n";
			board_.move('L');	
			break;
		case 2:
			cout<<"Your intelligent move is U\n";
			board_.move('U');
			break;
		case 3:
			cout<<"Your intelligent move is D\n";
			board_.move('D');
			break;
		}		
			
	}
	void move(char mov)
	{
		board_.move(mov);
	}
	void solvePuzzle()
	{
		board_.solvePuzzle();// I used the board_ object because the puzzle array is private.
	}
	
	
	
};

int main(int argc, char** argv)
{
	NPuzzle game;//Our npuzzle class game object ..
	srand( time(0) );
	int row,column;
	cout<<"***Welcome This Puzzle Game***"<<endl;
	cout<<"**Move Down to D**"<<endl;
	cout<<"**Move Up to U**"<<endl;
	cout<<"**Move Left to L**"<<endl;
	cout<<"**Move Right to R**"<<endl;
	cout<<"**Move Intelligent to I**"<<endl;
	cout<<"**Move Shuffle to S**"<<endl;
	cout<<"**Solves the problem from the current configuration using the new intelligent algorithm to V**"<<endl;
	cout<<"**Prints a report about how many moves have been done and if the solution is found to T**"<<endl;
	cout<<"**Asks a file name and saves the current board configuration as a loadable shape file to E**"<<endl;
	cout<<"**Asks a file name and loads the current board configuration from the shape file to O**"<<endl;
	cout<<"*Exit to Q**"<<endl;
	if(argc==1)
	{	
		cout<<"**Enter the number: ";
		cin >> row;
		column=row;
		game.setsize(row,column);//to determine row and column
	}
	else
	{
		game.board_.b_flag=1;
		game.readFromFile(argv[1]);//accessing the public function of the object ..
	}
	// the puzzle is filled with consecutive numbers ...
	while(1)
	{
		game.shuffle();
		if(game.board_.row%2 != 0) // to see if the number of rows and columns is even or odd ..
		{
			if(game.board_.return_inversion_number()%2 == 0)// can be solved if the inversion number is even.
				break;
			else // it must be refilled if it is unique because it cannot be solved.
				continue;
		}
		else // if double, different rules are required .. position of x from bottom counts.
		{
			if(game.board_.return_inversion_number()%2 == 0)// if inversion is even, position of x from bottom must be odd
			{
				if(game.board_.x%2 != 0)// where x is the value of i .. (i, j) ıf so, it can be solved.
				{
					break;
				}
				else//unsolvable..
				{
					continue;
				}
			}
			if(game.board_.return_inversion_number()%2 != 0)//if inversion is odd, position of x from bottom should be even

			{
				if(game.board_.x%2 == 0)//where x is the value of i .. (i, j) ıf so, it can be solved.
				{
					break;
				}
				else//unsolve
				{
					continue;
				}
			}
			
		}
	}
	cout<<"Your initial random board is"<<endl;
	game.print();//shows the original state.
	
	char commend;
	int count=0,select;
	
	cout<<"Your move: ";
	cin>>commend;
	count++;
	while(commend != 'Q')//Continue until you receive the Q command.
	{
		
		switch(commend)//switch structure works according to the command given ..
		{
			case 'D':
				game.move('D');
				break;
			case 'U':
				game.move('U');
				break;
			case 'L':
				game.move('L');
				break;
			case 'R':
				game.move('R');
				break;
			case 'S':
				game.shuffle();
				break;
			case 'I':
				game.moveIntelligent();
				break;
			case 'E':
				char save_name[50];
				cout<<"What is your file name"<<endl;//get file name
				cin>>save_name;
				game.writeToFile(save_name);
				break;
			case 'O':
				char load_name[50];
				cout<<"What is your file name"<<endl;
				cin>>load_name;
				game.readFromFile(load_name);
				break;
			case 'T':
				if(game.board_.isSolved()==1)//solved control
					cout<<"Problem Solved!"<<endl;
				else
					cout<<"Problem not Solved"<<endl;
				cout<<"Total number of moves "<<count<<endl;
				break;
			case 'V':
				game.solvePuzzle();
		}
		game.print();//to print the current version
		if(game.board_.isSolved()==1)//solved control.
		{
			cout<<"Problem Solved!"<<endl;
			cout<<"Total number of moves "<<count<<endl;
			break;
		}
		cout<<"Your move: ";
		cin>>commend;
		count++;//To find out how many moves he made.
	}

}
	
	

