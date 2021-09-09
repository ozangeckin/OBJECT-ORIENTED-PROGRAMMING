#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


void display(int puzzle[][9],int row,int column)//To show the snapshot of the puzzle ..
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
int control(int puzzle[][9] , int row)//When the puzzle is solved its control ..
{
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < row ; j++)
		{
			if(puzzle[i][j]!=(i*row)+j+1)
				return 0;
		}
	}
	return 1;
}
int return_inversion_number(int puzzle[][9], int row)//I used the inversion number for the solvable test.
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

int main(int argc, char** argv)
{
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
	cout<<"**Asks a file name and loads the current board configuration from the shape file to Y**"<<endl;
	
	int row,i=0,size=0,column,flag=0;
	int x,y;
	fstream inputStream ;
	ofstream forsave;
	ifstream forload;
	string filename,num,save_name,load_name;
	srand( time(0) );
	int row_bb=1;
	int random;
	int arr[81];
	int puzzle[9][9];
	int array[81];
	if(argc==1)
	{	
		cout<<"Please enter row number"<<endl;
		cin >> row;
		column=row;
		size = row*row;
	}
	else
	{
		inputStream.open(argv[1]);
		for(int i=0;i<9&&!inputStream.eof();i++)
		{
			for(int j=0;j<9&&!inputStream.eof();j++)
			{	
				if(flag==1)
					row_bb++;//to find row and column
				inputStream>>num;//reads numbers from file
				size++;
				if(num=="bb")//bb to protect the place
				{
					flag=1;
					puzzle[i][j] = -2;
					x=i;
					y=j;
				}
				else
				{
					puzzle[i][j] = ((int)num[0]-'0')*10 + (int)num[1]-'0';//are synchronized from the file, respectively
				}
			}
		}
		column=--row_bb;
		row=size/column;
	}
	
	while(1)
	{
		if(argc==1)
		{
			for(i =1 ; i <= size ; i++ )
			{
				array[i-1]=i;
			}	
			for(i=0 ; i<row ; i++)
			{
				for(int j=0 ; j<column ; j++)
				{
					while(1)
					{
						random = rand() % (size-1-0+1);
						if(array[random] != -1)//so that no the same number ..
							break;
					}
					if(array[random] == size)
					{
					 	x=i;//position of x from bottom will be needed for the value
						y=j;
						array[random]=-2;
					}
					if(argc==1)
					{
						puzzle[i][j] = array[random];//The puzzle is randomly filled ..
						array[random] = -1;
					}			
				}
			}
		}
		if(argc==2)
		{
			for(int i = 0 ; i < size*row ; i++)
				{
					random = rand() % (3-0+1);//For random mixing ..
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
		}
		if(row%2 != 0) //To understand whether the number of rows and columns is double or odd ..
		{
			if(return_inversion_number(puzzle,row)%2 == 0)//can be solved if the inversion number is even.
				break;
			else //if it is unique it must be refilled because it cannot be solved.
				continue;
		}
		else //if it is double, different rules are required. position of x from bottom counts.
		{
			if(return_inversion_number(puzzle,row)%2 == 0)//if inversion is even, position of x from bottom must be odd
			{
				if(row-x%2 != 0)//x can be solved if i value is found (i, j) ..
				{
					break;
				}
				else//unsolvable..
				{
					continue;
				}
			}
			if(return_inversion_number(puzzle,row)%2 != 0)//if inversion is odd, position of x from bottom must be even
			{
				if(row-x%2 == 0)//x can be solved if i value is found (i, j) ..
				{
					break;
				}
				else//unsolvable..
				{
					continue;
				}
			}	
		}
	}
	
	cout<<"Your initial random board is"<<endl;
	display(puzzle,row,column);//The first version is shown.
	
	char move;
	int count=0,select;
	
	cout<<"Your move: ";
	cin>>move;
	count++;
	while(move != 'Q')//Continue until you receive the Q command.
	{
		
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
					random = rand() % (3-0+1);//For random mixing ..
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
				
			case 'I'://The most logical direction is selected with if else structures.
				if (x == row-2 && y == column-1)
				{
					select = 0;
					
				}
				else if (x == row-1 && y == column-2)
				{
					select = 3;
				}
				else if (y == column-1 )
				{
					select = 0;
				}
				else if (x == row-1)
				{
					select =3;
				}
				else if (x == row-2 && y ==row-2)
				{
					if(puzzle[row-1][row-3]+1 == puzzle[row-2][row-1] )
					{
						select = 3;
					}
						
					else if(puzzle[row-2][row-3]+1 == puzzle[row-1][row-2] )
					{
						select = 0;
					}
				}
				else if(x == row-3 && y == row-2)
				{
					if(puzzle[row-3][row-3]+1 == puzzle[row-3][row-1] )
					{
						select = 3;
					}
						
					else if(puzzle[row-3][row-3]+1 == puzzle[row-2][row-2] )
					{
						select = 0;
					}
				}
				switch(select)
				{
						case 0:
							cout<<"Intelligent move chooses D"<<endl;
							if(x==row-1||puzzle[x+1][y]==0)//border controls ..
								break;
							puzzle[x][y]=puzzle[x+1][y];
							puzzle[x+1][y]=-2;
							x=x+1;
							
							break;
						case 1:
							cout<<"Intelligent move chooses U"<<endl;
							if(x==0||puzzle[x-1][y]==0)
								break;
							puzzle[x][y]=puzzle[x-1][y];
							puzzle[x-1][y]=-2;
							x=x-1;
							break;
						case 2:
							cout<<"Intelligent move chooses L"<<endl;
							if(y==0||puzzle[x][y-1]==0)
								break;
							puzzle[x][y]=puzzle[x][y-1];
							puzzle[x][y-1]=-2;
							y=y-1;
							break;
						case 3:
							cout<<"Intelligent move chooses R"<<endl;
							if(y==column-1||puzzle[x][y+1]==0)
								break;
							puzzle[x][y]=puzzle[x][y+1];
							puzzle[x][y+1]=-2;
							y=y+1;
							
							break;
					}
				break;
			case 'T':
				if(control(puzzle,row)==1)//solved control ..
					cout<<"Problem Solved!"<<endl;
				else
					cout<<"Problem not Solved"<<endl;
				cout<<"Total number of moves "<<count<<endl;
				break;
			case 'E':
				cout<<"What is your file name"<<endl;//retrieves file name
				cin>>save_name;
				forsave.open(save_name);
				for(int i=0 ; i<row;i++)
				{
					for(int j=0 ; j<column;j++)
					{
						if(puzzle[i][j]<10&&puzzle[i][j]>=0)
							forsave<<"0";//save single-digit numbers with zeros.
						if(puzzle[i][j]==-2)
						{
							forsave<<"bb "; // bb don't get lost
							continue;
						}
						forsave<<puzzle[i][j]<<" ";//numbers are written to file
					}
					forsave<<endl;
				}
				break;
			case 'Y':
				cout<<"What is your file name"<<endl;
				cin>>load_name;
				forload.open(load_name);
				for(int i=0;i<9&&!forload.eof();i++)//until the file is finished ..
				{
					for(int j=0;j<9&&!forload.eof();j++)
					{	
						
						forload>>num;//reads numbers from file
						if(num=="bb")//bb to protect the place
						{
							puzzle[i][j] = -2;
							x=i;
							y=j;
						}
						else
						{
							puzzle[i][j] = ((int)num[0]-'0')*10 + (int)num[1]-'0';//are synchronized from the file, respectively

						}	
					}
				}
				break;
			case 'V': //If else, the most logical move is selected.
				select=0;//the selection must be reset ..
				if(x>row/2)//'bb' daha aşağıda bir yerde kalıyordur
				{
					if(y>column/2)//'bb' is staying somewhere further down
					{
						if(puzzle[x][y-1]>puzzle[x][y+1])//If the left is larger than the right, there is a problem.
						{
							select=0;	
						}
						else//if this is not the case, it would be appropriate to move to the right
						{
							select=3;
						}
						if(puzzle[x-1][y]>puzzle[x+1][y])//If the above is greater than the following, there is problem ..
						{
							select=2;
						}
						else//if that is not the case, it would be appropriate to go down
						{
							select=0;
						}
					}
					else//'bb' stays somewhere higher
					{
						select=3;
					}
				}
				if(x<row/2)//'bb' stays somewhere higher
				{
					if(y>column/2)//'bb' stays somewhere far right
					{
						if(puzzle[x][y-1]>puzzle[x][y+1])//it is a problem as mentioned above but should move down because it is above
						{
							select=0;
						}
						else//if this is not the case, it would be appropriate to move to the right
						{
							select=3;
						}
						if(puzzle[x-1][y]>puzzle[x+1][y])//If the above is greater than the following, there is problem ..
						{
							select=0;
						}
						else//if this is not the case, it would be appropriate to move to the right
						{
							select=3;
						}
					}
					else//'bb' is a place to the left more left.
					{
						select=3;
					}
				}
				
				switch(select)
				{
					case 0:
						cout<<"Your more intelligent move : D"<<endl;
						if(x==row-1||puzzle[x+1][y]==0)//border controls ..
							break;
						puzzle[x][y]=puzzle[x+1][y];
						puzzle[x+1][y]=-2;
						x=x+1;
						break;
					case 1:
						cout<<"Your more intelligent move : U"<<endl;
						if(x==0||puzzle[x-1][y]==0)
							break;
						puzzle[x][y]=puzzle[x-1][y];
						puzzle[x-1][y]=-2;
						x=x-1;
						break;
					case 2:
						cout<<"Your more intelligent move : L"<<endl;
						if(y==0||puzzle[x][y-1]==0)
							break;
						puzzle[x][y]=puzzle[x][y-1];
						puzzle[x][y-1]=-2;
						y=y-1;
						break;
					case 3:
						cout<<"Your more intelligent move : R"<<endl;
						if(y==column-1||puzzle[x][y+1]==0)
							break;
						puzzle[x][y]=puzzle[x][y+1];
						puzzle[x][y+1]=-2;
						y=y+1;
						break;
				}
				break;
		}
		display(puzzle,row,column);//to show the final version ..
		
		if(control(puzzle,row)==1)//solved control ..
		{
			cout<<"Problem Solved!"<<endl;
			cout<<"Total number of moves "<<count<<endl;
			break;
		}
		cout<<"Your move: ";
		cin>>move;
		count++;//To find out how many moves you made ..
	}
	
	
	
	
	
	
	
	
}