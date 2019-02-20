#include  "stdafx.h"
#include <iostream>
#include "generalFunctions.h"
using namespace std;

int helpfulArgument(char * x, char * y) {
	cout << "Run the program in the following way:" << endl;
	cout << x << " " << y << endl;
	return TooManyArguments;
}

