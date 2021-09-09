package hw7;

import java.io.IOException;

/**
 *
 * @author OzanGECKIN
 */
public class Hw7 {

    /**
     * @param args the command line arguments
     */
	/**
	 * compares the moves of the boards
	 * @param AbstractBoard array x
	 * @return boolean
	 */
	public static boolean Global(AbstractBoard[] x)
	{
		for(int i=0;i<x.length;i++)
		{
			if(x[i].last_mov==x[i+1].last_mov) {
				return true;
			}
		}
		return false;
	}
    public static void main(String[] args) {
      System.out.println("!DRİVER!");
      System.out.println("Creating Objes");
      BoardArray2D boardd = new BoardArray2D(3,3);
      BoardArray2D boardd2 = new BoardArray2D(4,5);
      BoardArray1D board = new BoardArray1D(3,3);
      BoardArray1D board2 = new BoardArray1D(4,5);
      System.out.println("Testing 2DArray");
      boardd.reset();
      System.out.println("Reset is working");
      boardd.print();
      boardd.isSolved();
      System.out.printf("Two D array Puzzle of row 2 column 2 value = %d\n",boardd.cell(1, 1));
      System.out.println("\nShuffle in 2DArray");
      boardd.Move('S');
      boardd.print();
      boardd.isSolved();
      System.out.println("\nLeft move in 2DArray");
      boardd.Move('L');
      boardd.print();
      boardd.isSolved();
      System.out.println("\nDown move in 2DArray");
      boardd.Move('D');
      boardd.print();
      boardd.isSolved();
      System.out.println("\nRight move in 2DArray");
      boardd.Move('R');
      boardd.print();
      boardd.isSolved();
      System.out.println("\nUp move in 2DArray");
      boardd.Move('U');
      boardd.print();
      boardd.isSolved();
      
      boardd2.reset();
      System.out.println("Reset is working");
      boardd2.print();
      boardd2.isSolved();
      System.out.println("\nShuffle in 2DArray");
      boardd2.Move('S');
      boardd2.print();
      boardd2.isSolved();
      System.out.println("\nLeft move in 2DArray");
      boardd2.Move('L');
      boardd2.print();
      boardd2.isSolved();
      System.out.println("\nDown move in 2DArray");
      boardd2.Move('D');
      boardd2.print();
      boardd2.isSolved();
      System.out.println("\nRight move in 2DArray");
      boardd2.Move('R');
      boardd2.print();
      boardd2.isSolved();
      System.out.println("\nUp move in 2DArray");
      boardd2.Move('U');
      boardd2.print();
      boardd2.isSolved();
      boardd.Equals(boardd2);
      System.out.println("\nTwo D array Read from file");
      try {
		boardd.readFromFile("init.txt");
	} catch (IOException e) {

		e.printStackTrace();
	}
       boardd.writeToFile("twoDimensionalOutput.txt");
      System.out.println("\nTesting 1DArray");
      board.reset();
      
      System.out.println("Reset is working");
      board.print();
      System.out.printf("One D array Puzzle of row 2 column 1 value = %d\n\n",board.cell(1, 1));
      board.isSolved();
      System.out.println("\nOne D array Read from file");
      try {
		board2.readFromFile("init.txt");
	} catch (IOException e) {
		e.printStackTrace();
	}
      board2.reset();
      System.out.println("\nOne D array Reset is working");
      board2.print();
      System.out.println("");
      board2.isSolved();
      board2.Move('S');
      board2.movePrint();
      board2.Equals(board);
      board.writeToFile("oneDimensionalOutput.txt");

      AbstractBoard[] global = new AbstractBoard[2];
      global[0]=boardd;
      global[1]=boardd2;
      Global(global);
      System.out.printf("\nTwo dimensional array number :%d\n",boardd.numberofboards()+boardd2.numberofboards());
      System.out.printf("\nOne dimensional array number :%d\n",board.numberofboards()+board2.numberofboards());
    }
    
}