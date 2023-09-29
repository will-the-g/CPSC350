#include "fileProcessor.h"

// Constructor
fileProcessor::fileProcessor(string input, string output){
    this->input = input;
    this->output = output;
    // Clears the file 
    fstream outputFile;
    outputFile.open(output, ios::out);
    outputFile << "";
    outputFile.close();
}
// Destructor
fileProcessor::~fileProcessor(){
}
// Gets information from the input file and converts it to a int array
int* fileProcessor::processInput(){
    fstream inputFile;
    inputFile.open(this->input, ios::in);
    int L, N, V, coins, nothing, goombas, koopas, mushrooms;
    if (inputFile.is_open()){
        string line;
        int i = 0;
        while(getline(inputFile, line)){
            i++;
            switch(i){
                case 1:
                    L = stoi(line); // number of levels
                case 2:
                    N = stoi(line); // dimensions of each level
                case 3:
                    V = stoi(line); // number of lives
                case 4:
                    coins = stoi(line);
                case 5:
                    nothing = stoi(line);
                case 6:
                    goombas = stoi(line);
                case 7:
                    koopas = stoi(line);
                case 8:
                    mushrooms = stoi(line);
            }
        }
    }
    inputFile.close();
    static int inputArr[8] = {L, N, V, coins, nothing, goombas, koopas, mushrooms};
    return inputArr;
}

// outputs the level to the output file
void fileProcessor::outputLevel(char*** worldArr, int level, int N){
    fstream outputFile;
    outputFile.open(this->output, ios::app);
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            outputFile << worldArr[level][row][col];
        }
        outputFile << "\n";
    }
    outputFile << "=============\n";
    outputFile.close();
}