/*
 * ScrabbleDict.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: test
 */

#include "ScrabbleDict.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#define SPACE_DELIMITER " "


ScrabbleDict::ScrabbleDict(string FileName) {
	initPrimes();
	initWeigthArray();
	loadDict(FileName);

}

unsigned long long int ScrabbleDict::getHash(string str) {
	unsigned long long int hash = 1;
	for (char c: str) {
		hash *= primes[c - 'a'];
	}

	return hash;
}


void ScrabbleDict::initPrimes(){
	int count = 1;
	primes[0] = 2;
	int curNum = 3;
	while (count < NCHAR) {
		bool isPrime = true;
		for (int i = 0; i < count && isPrime; i++) {
			if (curNum % primes[i] == 0) {
				isPrime = false;
			}
		}
		if (isPrime)
			primes[count++] = curNum;
		curNum += 2;
	}
}

void ScrabbleDict::loadDict(string inFile) {
	string word;
	ifstream inputFile(inFile.c_str());
	if (inputFile.is_open()) {
		while (getline(inputFile, word)) {
			unsigned long long hash = getHash(word);
			insertInMap(hash, word);
		}
		inputFile.close();
	} else {
		cerr << "Unable to open file" << endl;
	}
}



void ScrabbleDict::insertInMap(unsigned long long key, string value) {
	map<unsigned long long, string>::iterator it;
	it = primeAnagram.find(key);
	bool hasKey = (it != primeAnagram.end());
	if (hasKey) {
		it->second = it->second + SPACE_DELIMITER + value;
	} else {
		primeAnagram.insert(std::pair<unsigned long long, string>(key, value));
	}
}


int ScrabbleDict::score(string str) {
	int wordScore = 0;

	for (unsigned int i = 0; i < str.length(); ++i) {
		int index = toupper(str[i]) - 'A';
		wordScore += alphaWeight[index];
	}

	return wordScore;
}

void ScrabbleDict::initWeigthArray() {
	for (int i = 0; i < NCHAR; ++i) {
		alphaWeight[i] = i + 1;
	}
}


string ScrabbleDict::getMaxScoreWord(string charsInHand){
	maxScoreWord.score = 0;
	maxScoreWord.words = "";

	//TODO
	//Call recursive function
	return maxScoreWord.words;
}

int calculateScore(string word) {
	string::iterator strIterator;
	int wordScore = 0;
	int scoreArray = {1, 2, 4, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
	for (unsigned int i = 0; i < str.length(); ++i) {
		int index = toupper(str[i]) - 'A';
		wordScore += scoreArray[index];
	}
	return wordScore;
}
void updateMaxScore(string word) {
	int hashVal = 0;
	int wordScore;
	hashVal = calculateHashValue(prefix);
	bool codeExists = primeAnagram.find(hashval) != primeAnagram.end();
	if (codeExists) {
		wordScore = calculateScore(word);
		if (wordScore > maxScoreWord.score) {
			maxScoreWord.score = wordScore;
			maxScoreWord.words = primeAnagram[hashVal];
		}
	}		
}

int findAllSubstrings(string prefix, string rest)
{
	if( rest.length() == 0 )
	{
		cout<<prefix<<endl;
		updateMaxScore(prefix);
	}
	else 
	{
		char c = rest[0];
		rest = rest.substr(1);
		substring( prefix , rest );
		
		prefix.push_back(c);
		substring( prefix , rest );
	}
	return count;
}
