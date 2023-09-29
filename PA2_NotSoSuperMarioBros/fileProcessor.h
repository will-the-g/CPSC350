#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
using namespace std;
#include <string>
#include <fstream>
#include <iostream>

class fileProcessor{
    public:
        fileProcessor(string input, string output);
        ~fileProcessor();
        int* processInput();
        void outputLevel(char*** worldArr, int level, int N);
    private:
        string input;
        string output;
};
#endif