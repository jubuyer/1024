//File name: /Users/laptopuser/Documents/cs135_codes/projects/game1024/TestBoard.cpp
#include <iostream>
#include "Board.hpp"
using namespace std;

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

    //coloring output in console output in c++ in linux
    //https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
    //cout << "\x1B[31mTexting\033[0m\t\t\n";
    //print out red text "Texting"

    //game.start();
    return 0;
}
