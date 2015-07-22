using namespace std;

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#define SPACE_DELIMITER " "

void getPrimes(int *primes, int n);
unsigned long long int getHash(string str, int primes[]);
string convertLongToString(unsigned long long int);
void insertInMap(string key, string value);
void writeMapToFile(std::map<string, string> primeAnagram); 

map<string, string> primeAnagram; 



int main () {
  string word;
  int primes[26];
  getPrimes(primes,26);

  ifstream inputFile ("sowpods.txt");
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
	
	
  writeMapToFile(primeAnagram);
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
  if (outFile.is_open()){
    for (it=primeAnagram.begin(); it!=primeAnagram.end(); ++it) {
    	if((it->second).find_first_of(" ") < (it->second).length()) {
    		outFile << it->second << '\n';
		}
    }
    outFile.close();
    cout<<"Written to file";
  }
  else{
    cout << "Unable to open file";
  } 	
}





