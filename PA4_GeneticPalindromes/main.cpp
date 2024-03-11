
#include "DNASeq.h"
#include "PalindromeFinder.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    string input = argv[1];
    fstream inputFile;
    string line;
    PalindromeFinder* finder = new PalindromeFinder();
    inputFile.open(input, ios::in);
    if (inputFile.is_open()){
        while(getline(inputFile, line)){
            if (line == "END"){ // if line is end then it breaks the loop and the program is over
                break;
            }
            line = line.substr(0, line.length() - 1); // deletes the /r at the end
            DNASeq* lineDNASeq = new DNASeq(line); 
            finder->findPalindromes(lineDNASeq);
            delete lineDNASeq;
        }
    }
    delete finder;
    return 0;
}