// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Lab2.h"
#include "generalFunctionss.h"
#include "gameBoardd.h"
#include "gamePieces.h"
using namespace std;

string lowerCase(string& s1) {
	for (unsigned int i = 0; i < s1.length(); ++i) {
		if (s1[i] >= 65 && s1[i] <= 92) {
			s1[i] = s1[i] + 32; 
		}
	}
	cout << s1 << endl; 
	return s1;
}

int main(int argc, char * argv[])
{
	if (argc != CorrectNumberOfArguments) {	
		return helpfulArgument(argv[programName], argv[inputFile]);
	}
	ifstream notOpenFile;
	notOpenFile.open(argv[inputFile]);
	if (!(notOpenFile)) {
		cout << "Unable to open file" << endl;; 
		//if unable to open file or file does not exist, returns this error
		return unableToOpenFile; 
	}
	else {
		unsigned int x;
		unsigned int y;
		ifstream& openedFile = notOpenFile;
		int result = readInDimensions(openedFile, x, y);
		while (result== unableToReadDimensions) {
			//to account for badly formed input 
			result = readInDimensions(openedFile, x, y);
			//unable to read dimensions from any line in the file 
			if (result == unableToReadLine) {
				return cannotExtractBoardDimensionsFromFile;
			}
		}
		//successfully extracted board dimensions
		int size = x*y; 
		vector<game_piece> pieces; 
		game_piece empty = game_piece(noColor, " ", " ");
		for (int i = 0; i < size; i++) {
			pieces.push_back(empty);
		}
		int readSuccess = readInGamePieces(openedFile, pieces, x, y);
		if (readSuccess == noPiecesRead) {
			cout << "Were not able to read in any game pieces, check format of file" << endl; 
			return noPiecesRead; 
		}
		else {
			cout << pieces.size() << endl; 
			cout << size << endl; 
			return (printBoard(pieces, x, y));
		}
	}
}


