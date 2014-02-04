import java.io.*;
import java.util.*;

class Maze
{
   char [][] matrix;
   boolean [][] visited;
   int rowcount;
   int colcount;

   public Maze(int r, int c)
   {
      rowcount = r; 
      colcount = c;
      matrix = new char [r][c];
      visited = new boolean [r][c];
      fillMatrix();
   }

    public Maze(String filename)
    {
	File file = new File(filename);
	readMatrix(file);
    }

   private void fillMatrix()
   {
      Random generator = new Random();
      int i, j;
      for (i=0; i<rowcount; i++)
         for (j=0; j<colcount; j++)
            if (generator.nextDouble() < 0.7)
               matrix[i][j] = ' ';
            else
               matrix[i][j] = 'X';
      matrix[0][0] = matrix[rowcount-1][colcount-1] = ' ';
   }

   private void readMatrix(File file)
   {
      TextReader reader;
      try
      {
         reader = new TextReader(file);
         rowcount = reader.readInt();
         colcount = reader.readInt();
         reader.skipLine();
         matrix = new char [rowcount][colcount];
         visited = new boolean [rowcount][colcount];
         for (int row=0; row<rowcount; row++)
         {
            reader.readChar();
            for (int col=0; col<colcount; col++)
            {
               matrix[row][col] = reader.readChar();
               reader.readChar();
            }
            reader.skipLine();
         }
      }
      catch(IOException e)
      {
         System.out.println(e.getMessage());
         return;
      }
   }

   public void findPath()
   {
      int i, j;
      for (i=0; i<rowcount; i++)
         for (j=0; j<colcount; j++)
            visited[i][j] = false;
      Cell destination = findPath(new Cell(0,0));
      if (destination == null)
         System.out.println("No path");
      else
      {
         System.out.println("Path:");
         showPath(destination);
         System.out.println('\n');
         markTrail(destination);

         drawPath();
         System.out.println();         
      }
   }

   private Cell findPath(Cell current)
   {
      int row = current.row;
      int col = current.column;
      Cell destination = null;

      visited[row][col] = true;
      if (row == rowcount-1 && col == colcount-1)
         return current;
      // try east
      if (feasible(row, col+1))
         destination = findPath(new Cell(row, col+1, current));
      // try south
      if (destination == null && feasible(row+1, col))
         destination = findPath(new Cell(row+1, col, current));
      // try west
      if (destination == null && feasible(row, col-1))
         destination = findPath(new Cell(row, col-1, current));
      // try north
      if (destination == null && feasible(row-1, col))
         destination = findPath(new Cell(row-1, col, current));
      return destination;
   }

   private void showPath(Cell curcell)
   {
      if (curcell != null)
      {
         showPath(curcell.previous);
         System.out.print(" ("+curcell.row+','+curcell.column+')');
      }
   }

   private boolean feasible(int row, int col)
   {
      if (row < 0 || row >= rowcount || col < 0 || col >= colcount)
         return false;
      else
         return (matrix[row][col] == ' ' && !visited[row][col]);
   }


   private void markTrail(Cell start)
   {
      for (int i=0; i<rowcount; i++)
         for (int j=0; j<colcount; j++)
            visited[i][j] = false;
      Cell current = start;
      while (current != null)
      {
         visited[current.row][current.column] = true;
         current = current.previous;
      }
   }

   private void drawPath()
   {
      int i, j;
      for (i=0; i<rowcount; i++)
      {
         for (j=0; j<colcount; j++)
         {
            System.out.print("|");
            if (visited[i][j])
               System.out.print(".");
            else
               System.out.print(""+matrix[i][j]);
         }
         System.out.println("|");
      }
   }
   

   public void show()
   {
      int i, j;
      System.out.println("" + rowcount + " " + colcount);
      for (i=0; i<rowcount; i++)
      {
         for (j=0; j<colcount; j++)
            System.out.print("|"+matrix[i][j]);
         System.out.println("|");
      }
      System.out.println();
   }

   private class Cell
   {
      int row;
      int column;
      Cell previous;
      public Cell (int r, int c)
      {
         row = r;
         column = c;
         previous = null;
      }
      public Cell (int r, int c, Cell p)
      {
         row = r;
         column = c;
         previous = p;
      }
   }
}















