#pragma once
#include "stdafx.h"
#include <iostream>
#include "gamePieces.h"
using namespace std; 

int readInDimensions(ifstream& file, unsigned int& x, unsigned int& y);

int readInGamePieces(ifstream& file, vector<game_piece>& pieces, unsigned int& x, unsigned int& y);

int printBoard(const vector<game_piece>& pieces, unsigned int width, unsigned int height); 

enum gameDimensionEnums { dimensionSuccess, unableToReadLine, unableToReadDimensions, cannotExtractBoardDimensionsFromFile};

enum gamePiecesEnums {pieceSuccess, noPiecesRead};

enum printBoardEnums {printSuccess, dimensionMismatch};
