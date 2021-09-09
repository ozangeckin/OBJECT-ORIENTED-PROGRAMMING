
package hw7;

import java.util.Random;
import java.io.*;
/**
 *
 * @author OzanGECKIN
 */
public class BoardArray2D extends AbstractBoard{
	
	int k;
	
    public BoardArray2D()
    {
        this.puzzle = new int[8][8];
        
    }
    public BoardArray2D(int row,int col)
    {
    	super(row,col);
        this.puzzle = new int[row][col];
       
    }
    private int puzzle[][];
	private BufferedReader br;
	
	/**
     * Two dimensional  array of print 
     */
    @Override
    public void print() {
       
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
        {
           if(puzzle[i][j]==-2)
           {
               System.out.print("   ");
               continue;
						
		    }				
		    if(puzzle[i][j]<10)
                    {
                        System.out.printf("0");
		    }
		    System.out.printf(puzzle[i][j]+" ");
		
	        }			
		System.out.println("\n");
		
	}
    }
    /**
     * fills the board in sequence.
     */

    @Override
    public void reset() {
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
    /**
     * index control and return the value in that index
     * @param x__
     * @param y__
     * @return integer
     */
    @Override
    public int cell (int x__,int y__)
    {
    	if(x__<0||x__>column-1||y__<0||y__>row-1)
    	{
    		System.err.println("invalid value");
    		System.exit(1);
    	}
    	
    	return puzzle[x__][y__];
    }
    /**
     * Compares 2-dimensional arrays
     * @param obje2
     * @return boolean
     */
    public boolean Equals(BoardArray2D obje2)
    {
    	if(this.equals(obje2))
    	{
    		System.out.println("Boards equals");
    		return true;
    		
    	}
    	System.out.println("Boards not equals");
    	return false;
    }
    /**
     * checks the release of the board
     */
    @Override
    public void readFromFile(String fileName) throws IOException {

        File f=new File(fileName);     //Creation of File Descriptor for input file
        FileReader fr=new FileReader(f);   //Creation of File Reader object
        br = new BufferedReader(fr);
        int c = 0;             
        while((c = br.read()) != -1)         //Read char by Char
        {
              char character = (char) c;          //converting integer to char
              if(character=='b')
              {
            	  character=' ';
              }
              System.out.print(character);        //Display the Character
        }    
    }
    /**
     * Creates the named.txt file given by fileName
     * @param String fileName
     */
    @Override
    public void writeToFile(String fileName) 
    {
    	try
    	{
    	    PrintWriter pr = new PrintWriter(fileName);    
    	    
    	    for (int i=0; i<row ; i++)
    	    {
    	    	for(int j=0;j<column;j++)
    	    	{
    	    		if(puzzle[i][j]<10&&puzzle[i][j]>=0)
    	    		{
    	    			pr.print("0");
    	    		}
    	    		if(puzzle[i][j]==-2)
    	    		{
    	    			pr.print("bb");
    	    			continue;
    	    		}
    	        pr.print(puzzle[i][j]+" ");
    	    	}
    	    	pr.print("\n");
    	    }
    	    pr.close();
    	}
    	catch (Exception e)
    	{
    	    e.printStackTrace();
    	    System.out.println("No such file exists.");
    	}
    }

    @Override
    public int isSolved() {
        	for(int i = 0 ; i < row ; i++)
		{
			for(int j = 0 ; j < column ; j++)
			{
				
				if(puzzle[i][j]!=(i*row)+j+1 && puzzle[row-1][column-1]!=-2)
                                {
                                    System.out.println("Puzzle is not solved");
                                    return 0;
                                }
			}
		}
		System.out.println("Congratulations!!Puzzle is solved");
		return 1;	
    }
    /**
     * it moves the space by making swaps with the move commands it receives.
     * @param move
     */
    @Override
    public void Move(char move) {
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
				Random r = new Random();
				int random = r.nextInt(3);//For random mixing ..
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
			}}
    
}