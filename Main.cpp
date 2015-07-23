//============================================================================
// Name        : Scrabble.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ScrabbleDict.h"




using namespace std;

int main(int argc, char **argv) {
	/*
	 if(argc < 3) {
	 cerr << "USAGE " << argv[0] << " DICTFILE CHARINHAND" << endl;
	 return -1;
	 }
	 */
	string inputFile = "sowpods.txt";
	string charsInHand = "qwertyuiopasdfghjkl"; //argv[2];


	ScrabbleDict scrabbledict(inputFile);

	string validWord = scrabbledict.getMaxScoreWord(charsInHand);
	cout << validWord <<endl;

	return 0;
}
