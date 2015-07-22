using namespace std;

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<sstream>
#include<map>

void getPrimes(int *primes, int n);
unsigned long long int getHash(string str, int primes[]);
string convertLongToString(unsigned long long int);
void insertInMap(string key, string value);
void displayMap(std::map<string, string> primeAnagram); 

map<string, string> primeAnagram;	//need to make it local and send by reference



int main () {
	string word;
	int primes[26];
	getPrimes(primes,26);

	ifstream inputFile ("words.txt");
	if (inputFile.is_open()){
		while ( getline (inputFile,word) ){
			string hash = convertLongToString(getHash(word,primes));
			insertInMap(hash, word);
			//cout << hash<<endl;
			//getchar();
		}
		inputFile.close();
	}
	else {
		cout << "Unable to open file";
	} 
	
	
	displayMap(primeAnagram);
	return 0;
}


unsigned long long int getHash(string str,int primes[]) {
	unsigned long long int hash=1;
	for (int i = 0; i< str.length(); i++) {
		hash *= primes[str[i]-'a'];
	}

	return hash;
}

void getPrimes(int *primes, int n) {
	int count = 1;
	primes[0] = 2;
	int curNum = 3;
	while (count < n) {
		bool isPrime = true;
		for ( int i = 0; i < count && isPrime; i++){
			if ( curNum % primes[i] == 0 ) {
				isPrime = false;
			}
		}
		if (isPrime) primes[count++] = curNum;
		curNum+=2;
	}
}

string convertLongToString(unsigned long long int hash){
	string hashString;
	stringstream strStream;
	strStream << hash;
	strStream >> hashString;
	return hashString;
}

void insertInMap(string key, string value) {
	map<string, string>::iterator it = primeAnagram.begin();
	
	if( primeAnagram.count(key) ) {
		it = primeAnagram.find( key );
		it -> second = it->second + " " + value;
	}
	else {
		primeAnagram.insert ( std::pair<string, string>(key, value) );
	}
}
void writeMapToFile(map<string, string> primeAnagram) {
	map<string, string>::iterator it = primeAnagram.begin();
	ofstream outFile ("Anagram_Pairs.txt");
	if (myfile.is_open()){
	    for (it=primeAnagram.begin(); it!=primeAnagram.end(); ++it) {
	  			outFile << it->second << '\n';
		}
	    myfile.close();
  	}
  else{
  	cout << "Unable to open file";
  } 	
}





