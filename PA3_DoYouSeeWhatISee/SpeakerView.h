#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <iostream>
#include <string>
#include <fstream>
#include "MonoStack.h"
using namespace std;


class SpeakerView{
    public:
        SpeakerView(string input);
        ~SpeakerView();
        void computeOutput(string input, string output);
        

    private:
        int ColumnCount;
        int lineCount;
        MonoStack<double>** stackArr;


    





};


#endif