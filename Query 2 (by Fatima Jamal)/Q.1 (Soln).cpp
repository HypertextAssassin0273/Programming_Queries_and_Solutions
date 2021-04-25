#include <iostream>
using namespace std;

#define N 4
int grid[N][N] = {
   {0, 0, 0, 0,},
   {0, 0, 0, 0,},
   {0, 0, 0, 0,},
   {0, 0, 0, 0,}
};

bool isPresentInCol(int col, int num){ //check whether num is present in col or not
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInRow(int row, int num){ //check whether num is present in row or not
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
//check whether num is present in 2x2 box or not
   for (int row = 0; row < 2; row++)
      for (int col = 0; col < 2; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(){ //print the sudoku grid after solve
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         if(col == 2)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 1){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool findEmptyPlace(int &row, int &col){ //get empty location and update row and column
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}

bool isValidPlace(int row, int col, int num){
   //when item not found in col, row and current 2x2 box
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%(N/2) ,col - col%(N/2), num);
}

bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; //when all places are filled
   for (int num = 1; num <= N; num++){ //valid numbers are 1 - 4
      if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku()) //recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}

int main(){
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}
