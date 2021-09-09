package hw7;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
/**
 *
 * @author OzanGECKIN 
 * 
 */
public class BoardArray1D extends AbstractBoard{
    
    int i;
    String num;
    private int puzzle[];
    private BufferedReader br;
    private int puzzle_[][] = new int[81][81] ;
    
    
    public BoardArray1D()
    {
    	this.puzzle = new int[81];
    }
    public BoardArray1D(int row,int col)
    {
    	super(row,col);
    	this.puzzle = new int[row*column];
    }
    /**
     * One dimensional  array of print 
     */
    @Override
    public void print() {
        int k=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
                {
                    if(puzzle[k]==-2)
        	    {
                        System.out.print("   ");
            		continue;
						
		    }				
		    if(puzzle[k]<10)
                    {
                        System.out.printf("0");
		    }
		    System.out.printf(puzzle[k]+" ");
		    k++;
	        }			
		System.out.println("\n");
	}
    }

    /**
     * fills the board in sequence.
     */
    @Override
    public void reset()
    {
        	int q=1;
		int size_=row*column;
		for(int i=0;i<size_;i++){
			if(i==size_-1){
                            puzzle[i]=-2;
			}
			else{
                            puzzle[i]=q;
                            q++;
                }
		}
    }
    /**
     * Compares 1-dimensional arrays
     * @param obje2
     * @return boolean
     */
    public boolean Equals(BoardArray1D obje2)
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
     *Retrieves information from the file 
     */
    @Override
    public void readFromFile(String fileName) throws IOException 
    {
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
     * Creates the named.txt file given by fileNam 
     * @param  fileName
     */

    @Override
    public void writeToFile(String fileName) 
    {
    	int k=0;
    	try
    	{
    	    PrintWriter pr = new PrintWriter(fileName);    
    	    
    	    for (int i=0; i<row ; i++)
    	    {
    	    	for(int j=0;j<column;j++)
    	    	{
    	    		if(puzzle[k]<10&&puzzle[k]>=0)
    	    		{
    	    			pr.print("0");
    	    		}
    	    		if(puzzle[k]==-2)
    	    		{
    	    			pr.print("bb");
    	    			continue;
    	    		}
    	        pr.print(puzzle[k]+" ");
    	        k++;
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
    /**
     * checks the release of the board
     */
    @Override
    public int isSolved() 
    {
       	int flag=0;
	for(int i=0;i<size-2;i++){
            if(puzzle[i+1]-puzzle[i]==1)
            {
                flag++;
            }
	}
            if(flag==size-2)
            {
            	System.out.println("Congratulations!!Puzzle is solved\n");
            	return 1;
            }
            else{
            	System.out.println("Puzzle is not solved");
                return 0;
		}
    }
    /**
     * index control and return the value in that index
     * @param x__
     * @param y__
     * @return integer
     */
    @Override
    public int cell(int x__,int y__)
    {
    	if(x__<0||x>column-1||y__<0||y>row-1)
    	{
    		System.err.println("involid value");
    	}
    	return puzzle[column*y+row];
    	
    }

    @Override
    public void Move(char move) 
    {
    int k=0;
    
    	for(int i=0;i<row;i++) 
    	{
    		for(int j=0;j<column;j++)
    		{
    			puzzle_[i][j]=puzzle[k];
    			k++;
    			
    		}
    		
    	}
    		
    	 switch(move)//switch structure works according to the given command ..
   		{	
   		
   		case 'D':
   			if(x==row-1||puzzle_[x-1][y]==0)//border controls and zero controls ..
   				break;
   				puzzle_[x][y]=puzzle_[x+1][y];
    				puzzle_[x+1][y]=-2;
    				x=x+1;
    				break;	
   		case 'U':
   			if(x==0||puzzle_[x-1][y]==0)
   				break;
    				puzzle_[x][y]=puzzle_[x-1][y];
    				puzzle_[x-1][y]=-2;
    				x=x-1;
    				break;
    			
   		case 'L':
   			if(y==0||puzzle_[x][y-1]==0)
   				break;
    				puzzle_[x][y]=puzzle_[x][y-1];
    				puzzle_[x][y-1]=-2;
    				y=y-1;
    				break;
   		case 'R':
   			if(y==column-1||puzzle_[x][y+1]==0)
   				break;
    				puzzle_[x][y]=puzzle_[x][y+1];
    				puzzle_[x][y+1]=-2;
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
   						if(x==row-1||puzzle_[x+1][y]==0)//border controls ..
   							break;
   							puzzle_[x][y]=puzzle_[x+1][y];
   							puzzle_[x+1][y]=-2;
   							x=x+1;
   							break;
   					case 1:
   						if(x==0||puzzle_[x-1][y]==0)
   							break;
   							puzzle_[x][y]=puzzle_[x-1][y];
   							puzzle_[x-1][y]=-2;
   							x=x-1;
   							break;
   					case 2:
   						if(y==0||puzzle_[x][y-1]==0)
   							break;
   							puzzle_[x][y]=puzzle_[x][y-1];
   							puzzle_[x][y-1]=-2;
   							y=y-1;
   							break;
   					case 3:
   						if(y==column-1||puzzle_[x][y+1]==0)
   							break;
   							puzzle_[x][y]=puzzle_[x][y+1];
   							puzzle_[x][y+1]=-2;
   							y=y+1;
   							break;
   					}		
   				}
   				break;	

    
    }
    }
    /**
     * one-dimensional array after move print
     */
    	 public void movePrint()
    	 {
    		 for(int i=0;i<row;i++){
    				for(int j=0;j<column;j++)
    		                {
    		                    if(puzzle_[i][j]==-2)
    		        	    {
    		                        System.out.print("   ");
    		            		continue;
    								
    				    }				
    				    if(puzzle_[i][j]<10)
    		                    {
    		                        System.out.printf("0");
    				    }
    				    System.out.printf(puzzle_[i][j]+" ");
    				
    			        }			
    				System.out.println("\n");
    				
    			}
    	 }
}