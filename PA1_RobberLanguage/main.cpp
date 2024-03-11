#include <string>
#include <iostream>
#include "FileProcessor.h"
using namespace std;
int main(int argc, char** argv){
    string inputFile = argv[1];
    string outputFile = argv[2];
    FileProcessor FileProcessor1;
    FileProcessor1.processFile(inputFile, outputFile);
    return 0;
}