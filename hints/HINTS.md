# Task A Hints
(1) Implement constructors, we set max to be 0 and the target to be 32. Also, set numRows
and numCols, initialize panel as a two-dimensional array of numRows rows and numCols.    
  
- (1.1) For default constructor, set numRows and numCols to be 3, panel is twodimensional array with 3 rows and 3 columns, set max to be 0 and target to be 32.  
- (1.2) For Board(int m), set numRows to be m and numCols to be m if m is >= 1, otherwise,
set numRows and numCols to be 3. Set panel to be a two-dimensional array with
numRows rows and numCols columns, set max to be 0 and target to be 32.  
- (1.3) For Board(int m, int n), set numRows by m and numCols by n if both m and n are >=
1, otherwise, set numRows and numCols to be 3. Set panel to be a two-dimensional
array with numRows rows and numCols columns, set max to be 0 and target to be 32.  
  
(2) Define destructor, release the memory space pointed by panel and remember to handle
dangling pointer problem.
  
(3) Define print method, which prints panel as a tabular format, each number in a cell with 4-
character wide, if the number is 0, do not print it out. See sample output in the project. 
  
In this task, only submit Board.cpp to gradescope for grading. However, you should keep
Board.hpp and Board.cpp in the same directory of local computer for compilation.
  
After finishing this task, your code does not run yet, use g++ -std=c++11 -c Board.cpp to check
for compilation errors.
  
To test Task A, define TestBoard.cpp in the same directory as Board.hpp and Board.cpp, with
the following contents.

```
#include "Board.hpp"
int main()
{
  Board game; //create a default Board object game
  game.print(); //test print method of game
  Board game2(4);
    //create a Board object with four rows
    //and four columns
  game2.print(); //test print methd of game2
  Board game3(3, 4);
    //create a Board object with three rows
    //and four columns
  game3.print(); //test print methd of game3
  
  return 0;
}
```

# Task B Hints
Parameters row and col are row- and column-index of the chosen random empty cell. Use int&
to pass by reference since we need to return both row and column. In our program, the 
returned row- and column-index are not used. When we improve our code later on, say, set
text color in the newly chosen random cell to be red, we will need such information.
  
(2.1) Comments all constructors in the submission of Task A. But keep destructor
~Board() and method print and any helper function for print.
Reason: gradescope autograde scripts provide a correct version of constructors, in
case your constructors are incorrect in Task A, methods selectRandomCell and
noAdjacentSameValue in your Task B can still be graded separately.
  
(2.2) Define method noAdjacentSameValue, which checks whether the game can be over
or not. That is, if all cells are filled up (no empty cell, which represents zero, in the
panel) and no two adjacent cells have the same value, return true, otherwise,
return false.
  
(2.3) Define method selectRandomCell, which do the following  
- (a) Tally total number of empty cells (cells with number zero) in the panel.
- (b) If there is no empty cell, if no adjacent cells with same value, print “Game over. Try
again.” and exit the program.
- (c) If there is at least one empty cell, put the cell’s location, represented by row and
column, into a dynamically allocated array or a vector (will be introduced later) of
integers.   
  
Challenge: how to represent the cell’s row and column information by an int?
Think about how we label the seat numbers in a classroom with 3 rows and 4 columns.
  
In the following illustration, row index goes from 0 to 2 vertically, while column index
goes from 0 to 3 horizontally. Row 0 and column 0 is represented by 0, while the cell
with row index 1 and column index 2 is represented by 6.
```
 row\col 0   1    2    3
     +----+----+----+----+
    0|  0 |  1 | 2 |   3 |
     +----+----+----+----+
    1|  4 |  5 | 6 |   7 |
     +----+----+----+----+
    2|  8 |  9 | 10 | 11 |
     +----+----+----+----+
For example, suppose we have the following board layout.
row\col 0    1    2
     +----+----+----+
    0 |   |   1|    |
     +----+----+----+
    1 |   |   1|    |
     +----+----+----+
    2 |   |    |    |
     +----+----+----+
Then the number of empty cells is 7. We create an array with 7 integers.
```
