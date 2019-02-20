#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "gameBoardd.h"
#include "gamePieces.h"
using namespace std; 

int readInDimensions(ifstream& file, unsigned int& x, unsigned int& y) {
	string line; 
	if (getline(file, line)) {
		istringstream iss(line);
		if (iss >> x >> y) {
			return dimensionSuccess; 
		}
		else {
			return unableToReadDimensions; 
		}
	}
	else {
		return unableToReadLine; 
	}
}

int readInGamePieces(ifstream& file, vector<game_piece>& pieces, unsigned int& x, unsigned int& y) {
	string line; 
	string color; 
	string name; 
	string display; 
	unsigned int xCoordinate; 
	unsigned int yCoordinate; 
	bool wellFormed = false; 
	while (getline(file, line)) {
		istringstream iss(line);
		if (iss >> color >> name >> display >> xCoordinate >> yCoordinate) {
			//call function to convert string into enum & check if color is not invalid 
			piece_color board = colorStringToEnum(color);
			if (board != invalidColor) {
				if ((xCoordinate < x) && (yCoordinate < y)) {
					// compare coordinates of x and y to dimensions of game board
					wellFormed = true;
					unsigned int index = (x*xCoordinate) + yCoordinate;
					game_piece gp1 = game_piece(board, name, display);
					pieces[index] = gp1;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
		else {
			//failure to extract all 5 values
			continue;
		}
	}	
	//checking if there was even one well formed input to return success or not
	if (wellFormed == true) {
		return pieceSuccess; 
	}
	else {
		return noPiecesRead; 
	}

}

int printBoard(const vector<game_piece>& pieces, unsigned int x, unsigned int y) {
	if (x*y != pieces.size()) {
		return dimensionMismatch; 
	}
	else {
		cout << "Game Board:" << endl; 
		for (unsigned int row = (y - 1); row >= 0; row--) {
			cout << endl; 
			string space; 
			for (unsigned int column = 0; column < (x); ++column) {
				unsigned int index = (x*column) + row; 
				cout << pieces[index].display; 
			}
			if (row == 0) {
				break; 
			}
		}
		return printSuccess; 
	}
}



