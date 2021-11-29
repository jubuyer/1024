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
Start label empty seats from zero. From first row, move from left to right, afterwards,
go to the second row, move from left to right, and so on.  
The first empty cell with row index 0 and column index 0 is represented by 0.  
The second empty cell with row index 0 and column index 2 is represented by 2.  
The third empty cell with row index 1 and column index 0 is represented by 3.  
The fourth empty cell with row index 1 and column index 2 is represented by 5.  
Similarly, the last three empty cells (in the last row) are presented by 6, 7, and 8,
respectively.  
  
That is, we have an array [0, 2, 3, 5, 6, 7, 8].
If you cannot represent the cell’s row and column by an integer, here is another
approach. Define a struct to represent row and column, then use an array or vector of
this struct (a struct is a type) to record row and column information of each empty cell.  
  
- (d) Select a random element from the above array or vector, then convert the int back to
its original row and column, set the corresponding cell by 1.
For example, suppose a random integer 23 is generated, then 23 % 7 returns 2, where
7 is the size of the array. The remainder of any int divided by 7 falls in [0, 6], which is a
range of valid indices of an array of size 7.
The element indexed at 2 in the above array is 3, which corresponds to an empty cell
with row index 1 and column index 0. You need to convert 3 back to row index 1 and
column index 0 in a 3 x 3 panel. Afterwards, put number 1 to this cell.
- (e) Print the updated panel with the added cell.
- (f) With the added cell, if every cell is filled up and no adjacent cells with same values,
print “Game over. Try again.” Then exit the program.
In this task, only submit Board.cpp to gradescope for grading. However, you should keep
Board.hpp and Board.cpp in the same directory of local computer for compilation.
After finishing this task, your Board.cpp does not run yet, use g++ -std=c++11 -c Board.cpp to
check compilation errors.

# Task C Hints
Define code to press UP, DOWN, LEFT, RIGHT. That is, define pressUp, pressDown, pressLeft
and pressRight methods of Board.cpp.  
Note that selectRandomCell method is called in these above methods. In case your version of
selectRandomCell in Task B has errors, you would fail Task C. To avoid that scenario, we provide 
a corrected version of selectRandomCell in gradescope scripts. As a result, do not include your
definition of selectRandomCell and constructors/destructor in submission of Task C.  
1. From the submission of Task B, which includes print and selectRandomCell methods,
add definition of pressLeft, pressRight, pressDown, and pressUp methods.
2. When you define pressLeft, pressRight, pressDown, and pressUp methods, remember to
call selectRandomCell method in the end. This is because, after an arrow key is pressed,
a random empty cell is selected and number 1 is put in that cell, these steps are defined
in selectRandomCell.
3. Before submission, comment the definition of selectRandomCell since a correct version
of it will be provided by gradescope scripts. If you include the definition of
selectRandomCell method in submission of Task C, compiler would complain that that
method is redefined.
In short, only include codes for pressLeft, pressRight, pressUp, pressDown, and print
methods in Task C.
