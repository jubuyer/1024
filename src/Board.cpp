#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "time.h"
#include "Board.hpp"

using namespace std;

// Board::Board():Board(3, 3) {}
//
// Board::Board(int m):Board(m, m) {}
//
// Board::Board(int m, int n) {
//     if(m >= 1 && n >= 1) {
//         numRows = m;
//         numCols = n;
//     } else {
//         numRows = 3;
//         numCols = 3;
//     }
//
// 	allocateMemory();
// 	setTarget(32);
// 	max = 0;
// }
//
// void Board::allocateMemory() {
// 	panel = new int*[numRows];
// 	for(int i = 0; i < numRows; i++) {
// 		panel[i] = new int[numCols];
// 	}
// }
//
// Board::~Board() {
// 	for(int i = 0; i < numRows; i++) {
// 		delete[] panel[i];
// 		panel[i] = nullptr;
// 	}
//
// 	delete[] panel;
// 	panel = nullptr;
// }
//
// void Board::setTarget(int target) {
// 	this->target = target;
// }
//
// void Board::clear(){
// 	for(int i = 0; i < numRows; i++) {
// 		for(int j = 0; j < numCols; j++) {
// 			panel[i] = 0;
// 		}
// 	}
// }

struct Cell {
	int row;
	int col;
};

// void Board::selectRandomCell(int& row, int& col) {
// 	int emptyCells = 0;
// 	std::vector<Cell> cellInfo;
// 	if(noAdjacentSameValue()) {
// 		std::cout << "Game over. Try again." << std::endl;
// 		return;
// 	}
//
// 	for(int i = 0; i < numRows; i++) {
// 		for (int j = 0; j < numCols; j++) {
// 			if (panel[i][j] == 0) {
// 				cellInfo.push_back(Cell());
// 				cellInfo[emptyCells].row = i;
// 				cellInfo[emptyCells].col = j;
// 				emptyCells++;
// 			}
// 		}
// 	}
//
// 	//srand(time(1));
// 	int value = rand() % cellInfo.size();
//
// 	panel[cellInfo[value].row][cellInfo[value].col] = 1;
//
// 	print();
//
// 	if(noAdjacentSameValue()) {
// 		std::cout << "Game over. Try again." << std::endl;
// 		return;
// 	}
//
// 	return;
// }
//
// bool Board::noAdjacentSameValue() const {
// 	for(int i = 0; i < numRows; i++) {
// 		for (int j = 0; j < numCols; j++) {
// 			if (panel[i][j] == 0) {
// 				return false;
// 			}
// 		}
// 	}
// 	for(int i = 0; i < numRows; i++) {
// 		for (int j = 0; j < numCols-1; j++) {
// 			if(panel[i][j] == panel[i][j+1]) {
// 				return false;
// 			}
// 		}
// 	}
// 	for(int i = 0; i < numRows-1; i++) {
// 		for (int j = 0; j < numCols; j++) {
// 			if(panel[i][j] == panel[i+1][j]) {
// 				return false;
// 			}
// 		}
// 	}
//
// 	return true;
// }



void printBorder(int num) {
		for(int i = 0; i < num; i++) {
		if (i == 0) {
			std::cout << "+";
		}
		std::cout << "----+";
	}

}

void Board::pressDown()
{
    int* temp = new int[numRows];
    int toWrite;
    for (int j = 0; j < numCols; j++)
    {
        //initialize each element of temp to be 0
        for (int k = 0; k < numRows; k++)
            temp[k] = 0;

        //copy the non-zeros from the jth column
        //of panel to temp
        toWrite = numRows -1; //next position to write in temp
        for (int i = numRows-1; i >= 0; i--)
            if (panel[i][j] > 0)
            {
               temp[toWrite] = panel[i][j];
               toWrite--;
            }

        for (int k = numRows-1; k > 0; k--) //? k >= 0 is not correct, it would result in out of index exception in expression temp[k-1].
            if (temp[k] == temp[k-1])
            {
               temp[k] *= 2;

               //MISS
               if (max < temp[k])
                  max = temp[k];

               temp[k-1] = 0;
               k--; //k-- to skip adjacent pair
               //temp[k-1] and temp[k-2]
               //since temp[k-1] is merged with
               //temp[k] already.
               //This line can be omitted after
               //setting temp[k-1] = 0;
               //since if temp[k-2] is not zero,
               //no way to merge since
               //temp[k-1] != temp[k-2],
               //if temp[k-2] is zero,
               //then 0 merged with 0 does not
               //result in any actual difference.
            }

        int i = numRows -1;  //to write in jth column of panel, starting from the last row since we press down key, whose row index is numRows-1.
        int k = numRows -1; //can use for loop for k
        while (k >= 0)
        {
            if (temp[k] > 0)
            {
               panel[i][j] = temp[k];
               i--;
            }
            k--;
        }

        //For the remaining elements in the jth column, pad with 0.
        while (i >= 0)
        {
            panel[i][j] = 0;
            i--;
        }
    }

    delete[] temp;
    temp = nullptr;

    //MISS
    int row = -1, col = -1;
    selectRandomCell(row, col);
}

void Board::pressUp()
{
	int* temp = new int[numRows];
	int toWrite;
	for (int j = 0; j < numCols; j++)
	{
			//initialize each element of temp to be 0
			for (int k = 0; k < numRows; k++)
					temp[k] = 0;

			//copy the non-zeros from the jth column
			//of panel to temp
			toWrite = numRows -1; //next position to write in temp
			for (int i = numRows-1; i >= 0; i--)
					if (panel[i][j] > 0)
					{
						 temp[toWrite] = panel[i][j];
						 toWrite--;
					}

			for (int k = 0; k < numRows-1; k++) //? k >= 0 is not correct, it would result in out of index exception in expression temp[k-1].
					if (temp[k] == temp[k+1])
					{
						 temp[k] *= 2;

						 //MISS
						 if (max < temp[k])
								max = temp[k];

						 temp[k+1] = 0;
						 k++; //k-- to skip adjacent pair
						 //temp[k-1] and temp[k-2]
						 //since temp[k-1] is merged with
						 //temp[k] already.
						 //This line can be omitted after
						 //setting temp[k-1] = 0;
						 //since if temp[k-2] is not zero,
						 //no way to merge since
						 //temp[k-1] != temp[k-2],
						 //if temp[k-2] is zero,
						 //then 0 merged with 0 does not
						 //result in any actual difference.
					}

			int i = 0;  //to write in jth column of panel, starting from the last row since we press down key, whose row index is numRows-1.
			int k = 0; //can use for loop for k
			while (k < numRows)
			{
					if (temp[k] > 0)
					{
						 panel[i][j] = temp[k];
						 i++;
					}
					k++;
			}

			//For the remaining elements in the jth column, pad with 0.
			while (i < numRows)
			{
					panel[i][j] = 0;
					i++;
			}
	}

	delete[] temp;
	temp = nullptr;

	//MISS
	int row = -1, col = -1;
	selectRandomCell(row, col);
}

void Board::pressLeft()
{

}

void Board::pressRight()
{

}

void Board::print() const {
	//explained by gavin xiao
	for(int i = 0; i < numRows; i++) {
        printBorder(numCols);
        std::cout << "\n|";

        for(int j = 0; j < numCols; j++) {
            std::string temp = "";
            for(int k = 0; k < 4 - std::to_string(panel[i][j]).length(); k++) {
                temp += " ";
            }

            if(panel[i][j] == 0) {
                temp += " ";
            } else {
                temp += std::to_string(panel[i][j]);
            }

            std::cout << temp << "|";
        }

        std::cout << "\n";
    }

    // Prints out the bottom of the board +----+
    printBorder(numCols);
    std::cout << "\n";

    /*	****************DOES NOT FUNCTION**********************
	//top border of the board

	std::cout << '\n'; //skip to next iterations of the board border

	// int l = 0;
	for(int j = 0; j < numRows; j++) {
		for (int k = 0; k < numCols; k++) {
			// if ((k == 0) && ((j % 2) == 0)) {
			// 	std::cout << "|"; //first "border"
			// }
			// if (j % 2 == 0) { //if the row is even print the middle
			// 	std::cout << "   ";
			// 	if (panel[l][k] == 0) {
			// 		std::cout << " ";
			// 	} else {
			// 		std::cout << panel[l][k];
			// 	}
			// 	std::cout << "|";
			// } else if ((k == 0) && (j % 2) != 0) { //if row is odd
			// 	std::cout << "+----+";			   // print the seperator
			// } else if ((j%2) != 0) {
			// 	std::cout << "----+";
			// }
			std::string temp = "";
            for(int k = 0; k < 4 - std::to_string(panel[i][j]).length(); k++) {
                temp += " ";
            }

            if(panel[i][j] == 0) {
                temp += " ";
            } else {
                temp += std::to_string(panel[i][j]);
            }

            std::cout << temp << "|";
		}
		//l++;
		std::cout << '\n';
	}
	*****************DOES NOT FUNCTION********************* */
}
