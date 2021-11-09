# 1024
This is a game that is also available on their [website](http://1024game.org). Play it to get familiar
with it!
### Given a board of squares where some have numbers, and the rest are empty...
- You can use the arrow keys to move the numbered squares in any direction (left, right,
up, and down.)  
- All numbered squares will move in the direction that you select, at the same time, as far as 
they can go without taking over the space of another square that has a value.  
    • Every time you move these squares, a random, empty square will gain the value of 1.
    
- After moving them, any pair of squares that have the same value, in the selected
direction that are next to each other will be merged (the values of the two squares will
be added together and will become a single square).
  
- The squares do not increase in size-- you will gain an empty square after a
merge.
  • If you happen to have more than two squares of the same value in the same
direction that you are moving in and they are all next to each other, the equal
pairs closest to the edge of the direction you had selected will merge first.
  
  • When there are more than two identical values in adjacent cells (omitting empty
  cells), then the cells in the given direction have a higher precedence. For
  example, given a row in a 4-column board, where x is a space, as follows.  
  `2 x 2 2`  
  If we press ``LEFT``, the leftmost two identical value cells (ignoring empty cell in
  between) are merged and we get  
  `4 2 x x`  
  If we press ``RIGHT``, the rightmost two identical value cells are merged and we get  
  `x x 2 4` 
  
- You win if any of the squares have a value of 1024 at any point, and you lose if there are
no more empty squares!
  
- You lose if you are not able to merge anymore and all squares are taken up, and you
only gain a 1 if the direction you have selected moves any of the squares!
---
### Tasks
| Project Tasks           | Description                                                   |
|-----------------|---------------------------------------------------------------|
|Task A           | Define constructor for Board.cpp.                             |
|Task B           | Define code to select a random cell with value 1. That is, define selectRandomCell method of Board.cpp. |
|Task C           | Define code to press UP, DOWN, LEFT, RIGHT. That is, define pressUp, pressDown, pressLeft and pressRight methods of Board.cpp.   |
|Task D           | Define code to play a game, that is, define start method in Board.cpp. |

### How to work on the project
Download Board.hpp, TestBoard.cpp, makefile from blackboard, implement Board.cpp.

**Note:** For grading purpose, choose srand(1); when submit this project, thus the same random
sequence is chosen each time. You can change it to srand(time(NULL)); when you play with it

