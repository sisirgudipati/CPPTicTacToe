========================================================================
    CONSOLE APPLICATION : Lab2 Project Overview
========================================================================

AppWizard has created this Lab2 application for you.

This file contains a summary of what you will find in each of the files that
make up your Lab2 application.


Lab2.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Lab2.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Lab2.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Lab2.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

Sisir Gudipati 451212
Lab 2 

Design structure & decisions: Since both txt files provided only had square dimensions, in my design I only accounted for square board games. 

gamePieces.h & gamePieces.cpp: 
	1). Defined game_piece struct in gamePieces.h & defined in gamePieces.cpp. Also defined a boolean operator to test game_piece equality. 

gameBoardd.h & gameBoardd.cpp: 
	1). Function defined here to read in dimensions of the board from the first line. Enumerated errors defined in gameBoardd.h. 
	2). Function defined here to read in game pieces of the board from the subsequent lines of txt file. Enumerated errors defined in gameBoardd.h. 
	3). Function defined here to read print the pieces of the board, used a double for loop and ran into an error that was skipping one of the lines in tic-tac-toe.txt. 
	I learned that it was because two of the pieces were given the same position, so the first piece was being overwritten. I edited the text file with the help of a TA 
	to fix that. 

generalFunctions.cpp & generalFunctions.h
	1). generalFunctions.cpp holds my general file reading functions, outputs an error if there is more than 2 arguments (1 other than the executable). 

Test cases: 
	1). Indented the game dimensions a few lines down from the top to check if program continued to check until it found dimensions. 
	2). Changed the game dimensions to non-square dimensions. But my design decision was to leave it the way it was because most popular games are square dimensions. 
	3). Tried spacing lines and it worked as well.
	
Errors: Ran into a skipping line error in the tic-tac-toe file due to two pieces being indexed to the same position. Also ran into an error for figuring out how to 
link various source and header files together. I also decided to keep "using namespace std;" at the top of all my header and source files because I found out pretty late
that it wasn't best practice due to inheritance issues. In my future labs I will most definitely be more careful about this.  