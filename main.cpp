#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#define SPACE_DELIMITER " "
#define NCHAR 26

using namespace std;

void fillWeigthArray(int alphaWeight[]);
int score(string str, const int alphaWeight[]);
void getPrimes(int *primes, int n);
unsigned long long int getHash(string str, int primes[]);
void insertInMap(unsigned long long key, string value, map<unsigned long long, string> & primeAnagram);
void loadDict(string inFile, map<unsigned long long, string> &primeAnagram, int primes[]);
string getMaxScoreWord(string charsInHand, int wiegthArray[], map<unsigned long long, string> primeAnagram);

//void writeMapToFile(map<unsigned long long, string> primeAnagram) ;

int main(int argc, char **argv) {
	/*
	 if(argc < 3) {
	 cerr << "USAGE " << argv[0] << " DICTFILE CHARINHAND" << endl;
	 return -1;
	 }
	 */
	string inputFile = "sowpods.txt";
	string charsInHand = "ABCD"; //argv[2];
	int primes[NCHAR];
	map<unsigned long long, string> primeAnagram;

	getPrimes(primes, NCHAR);
	loadDict(inputFile, primeAnagram, primes);

	int wiegthArray[NCHAR]  = {};
	string validWord = getMaxScoreWord(charsInHand, wiegthArray, primeAnagram);

	cout << validWord <<endl;
	//writeMapToFile(primeAnagram);

	return 0;
}



string getMaxScoreWord(string charsInHand, int wiegthArray[], map<unsigned long long, string> primeAnagram){
	int maxScore = 0;
	string maxScoreWord;

	//TODO
	//Call recurive function
	return maxScoreWord;
}

void loadDict(string inFile, map<unsigned long long, string> &primeAnagram, int primes[]) {
	string word;
	ifstream inputFile(inFile.c_str());
	if (inputFile.is_open()) {
		while (getline(inputFile, word)) {
			unsigned long long hash = getHash(word, primes);
			insertInMap(hash, word, primeAnagram);
		}
		inputFile.close();
	} else {
		cerr << "Unable to open file" << endl;
	}
}

unsigned long long int getHash(string str, int primes[]) {
	unsigned long long int hash = 1;
	for (char c: str) {
		hash *= primes[c - 'a'];
	}

	return hash;
}

void getPrimes(int *primes, int n) {
	int count = 1;
	primes[0] = 2;
	int curNum = 3;
	while (count < n) {
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



void insertInMap(unsigned long long key, string value, map<unsigned long long, string> & primeAnagram) {
	map<unsigned long long, string>::iterator it = primeAnagram.begin();

	if (primeAnagram.count(key)) {
		it = primeAnagram.find(key);
		it->second = it->second + SPACE_DELIMITER + value;
	} else {
		primeAnagram.insert(std::pair<unsigned long long, string>(key, value));
	}
}


int score(string str, const int alphaWeight[]) {
	int wordScore = 0;

	for (unsigned int i = 0; i < str.length(); ++i) {
		int index = toupper(str[i]) - 'A';
		wordScore += alphaWeight[index];
	}

	return wordScore;
}

void fillWeigthArray(int alphaWeight[]) {
	for (int i = 0; i < NCHAR; ++i) {
		alphaWeight[i] = i + 1;
	}
}

/*

void writeMapToFile(map<unsigned long long, string> primeAnagram) {
	ofstream outFile("Anagram_Pairs.txt");
	if (outFile.is_open()) {
		for (map<unsigned long long, string>::iterator it = primeAnagram.begin();
				it != primeAnagram.end(); ++it) {
			if ((it->second).find_first_of(SPACE_DELIMITER)
					< (it->second).length()) {
				outFile << it->second << '\n';
			}
		}
		outFile.close();
		cout << "Written to file" << endl;
	} else {
		cerr << "Unable to open file" << endl;
	}
}

*/
