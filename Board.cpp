#include <iostream>

#include "Board.hpp"

Board::Board() {
	numCols = 3;
	numRows = 3;
}

Board::Board(int m) {
	numCols = m;
	numRows = m;
}

Board::Board(int m, int n) {
	numCols = m;
	numRows = n;
}

Board::~Board() {

}

void Board::print() const {
	int rows = this->numRows;
	int cols = this->numCols;

	//top border of the board
	for(int i = 0; i < cols; i++) {
		if (i == 0) {
			std::cout << "+";
		}
		std::cout << "----+";
	}

	std::cout << '\n'; //skip to next iterations of the board border

	for(int j = 0; j < rows*2; j++) {
		for (int k = 0; k < cols; k++) {
			if ((k == 0) && ((j % 2) == 0)) {
				std::cout << "|";
			}
			if (j % 2 == 0) {
				std::cout << "    |";
			} else if ((k == 0) && (j % 2) != 0) {
				std::cout << "+----+";
			} else if ((j%2) != 0) {
				std::cout << "----+";
			}
		}
		std::cout << '\n';
	}
}