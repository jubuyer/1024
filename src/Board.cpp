#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Board.hpp"

Board::Board():Board(3, 3) {}

Board::Board(int m):Board(m, m) {}

Board::Board(int m, int n) { 
    if(m >= 1 && n >= 1) {
        numRows = m;
        numCols = n;
    } else { 
        numRows = 3; 
        numCols = 3;
    }

	allocateMemory();
	setTarget(32);
	max = 0;
}

void Board::allocateMemory() {
	panel = new int*[numRows];
	for(int i = 0; i < numRows; i++) {
		panel[i] = new int[numCols];
	}
}

Board::~Board() {
	for(int i = 0; i < numRows; i++) {
		delete[] panel[i];
		panel[i] = nullptr;
	}

	delete[] panel;
	panel = nullptr;
}

void Board::setTarget(int target) {
	this->target = target;
}

void Board::clear(){
	for(int i = 0; i < numRows; i++) {
		for(int j = 0; j < numCols; j++) {
			panel[i] == 0;
		}
	}
}

void Board::selectRandomCell(int& row, int& col) {
	int emptyCells = 0;
	for(int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (panel[i][j] == 0) {
				emptyCells++;
			}
		}
	}
	if(noAdjacentSameValue()) {
		std::cout << "Game over. Try again.";
		return;
	}
}

bool Board::noAdjacentSameValue() const {
	for(int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (panel[i][j] == 0) {
				return false;
			}
		}
	}
	for(int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols-1; j++) {
			if(panel[i][j] == panel[i][j+1]) {
				return false;
			}
		}
	}
	for(int i = 0; i < numRows-1; i++) {
		for (int j = 0; j < numCols; j++) {
			if(panel[i][j] == panel[i+1][j]) {
				return false;
			}
		}
	}

	return true;
}



void printBorder(int num) {
		for(int i = 0; i < num; i++) {
		if (i == 0) {
			std::cout << "+";
		}
		std::cout << "----+";
	}

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
