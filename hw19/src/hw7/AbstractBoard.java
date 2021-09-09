package hw7;

import java.io.File;
import java.io.IOException;

/**
 *
 * @author OzanGECKIN
 */
public abstract class AbstractBoard {
    
    protected String fileName;
    protected File file;
    protected int row=0;
    protected int column=0;
    protected int x=0;
    protected int y=0;
    protected int location;//for space..
    protected char move;
    protected char last_mov='S';
    protected int boardnumber=0;
    protected int size;
    
    
    public static int numberOfMoves=0;
    public AbstractBoard(){boardnumber=boardnumber+1;}
    public AbstractBoard(int row,int col){
         setSize(row,col);
         boardnumber=boardnumber+1;
    }
    public abstract void print();
    public abstract void reset();
    public abstract void readFromFile(String fileName) throws IOException;
    public abstract int cell(int x__,int y__);
    public abstract void writeToFile(String fileName);
    /**
     *Size setting. 
     *@param x,y
     */

    public void setSize(int x,int y)
    {
        row=x;
	column=y;
	size=x*y;
    }
    public abstract int isSolved();
    public abstract void Move(char move);
     /**
     *x setting. 
     *@param x_
     */

    public void setX(int x_){x=x_;}
     /**
     *y setting. 
     *@param y_
     */
    public void setY(int y_){y=y_;}
     /**
      *calculates how much board
      *@return boardnumber
      */
    public int numberofboards(){return boardnumber;}  
     /**
      *calculating the last move
      *@param move
      *@return last_mov 
      */
	
    public char lastmove(char move){
    	numberOfMoves++;
	last_mov=move;
	return last_mov;
    }

}