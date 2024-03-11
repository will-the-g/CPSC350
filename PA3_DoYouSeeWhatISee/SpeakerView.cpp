#include "SpeakerView.h"



SpeakerView::SpeakerView(string input){
    fstream inputFile;
    inputFile.open(input, ios::in);
    this->ColumnCount = 1;
    if (inputFile.is_open()){
        string line;  
        for (int i = 0; i < 2; i++){
            getline(inputFile, line);
            if (i == 1){
                int length = line.length();
                for (int i = 0; i < length; i++){ // loops through the line
                    if (line.at(i) == ' '){  // checks if its a space (or not a digit)
                        line.erase(0, i + 1); // removes each digit + space
                        this->ColumnCount++;
                        i = 0; // resets the loop
                        length = line.length(); // resets the length
                    }
                }
            }
        }
    }
    inputFile.close();
    inputFile.open(input, ios::in);
    string line;
    if (inputFile.is_open()){
        this->lineCount = 0;
        while(getline(inputFile, line)){
            this->lineCount++;
        }
        // Creates an array of stacks for each column
        this->stackArr = new MonoStack<double>* [this->ColumnCount];
        for (int i = 0; i < this->ColumnCount; i++){
            this->stackArr[i] = new MonoStack<double>(this->lineCount - 2, true);
        }
    }
    inputFile.close();
}

SpeakerView::~SpeakerView(){
    for (int i = 0; i < this->ColumnCount; i++){
        delete stackArr[i];
    }
    delete[] stackArr;
}


void SpeakerView::computeOutput(string input, string output){
    
    fstream inputFile;
    inputFile.open(input, ios::in);
    string lineArr[this->lineCount];
    string line;
    int i = 0;
    while(getline(inputFile, line)){
        lineArr[i] = line;
        i++;
    }
    inputFile.close();
    int currColumn;
    int currLine = 1; // starts at 2nd to last line
    while (currLine < this->ColumnCount){
        currColumn = 0;
        string line = lineArr[this->ColumnCount - currLine];
        int length = line.length();
        for (int i = 0; i < length; i++){
            if (line.at(i) == ' '){
                double number = stod(line.substr(0, i)); // grabs the number
                line.erase(0, i + 1); // erases number + space
                this->stackArr[currColumn]->push(number);
                i = 0;
                length = line.length(); // resets loop
                currColumn++;
                
                
            }
        }
        // runs one more time to account for the last number that didn't have a space after it
        for (int i = 0; i < line.length(); i++){
            if (line.at(i) == '\r'){
                double number = stod(line.substr(0, i));
                this->stackArr[currColumn]->push(number);
                
            }
        }
        currLine++;
    }
    fstream outputFile;
    outputFile.open(output, ios::out);
    for (int i = 0; i < this->ColumnCount; i++){
        outputFile << "In Column " << i << ". There are " << this->stackArr[i]->getSize() << " people that can see. Their heights are: ";
        int count = this->stackArr[i]->getSize();
        for (int j = 0; j < count; j++){
            if (this->stackArr[i]->getSize() == 1){
                outputFile << this->stackArr[i]->pop();
            }else{
                outputFile << this->stackArr[i]->pop() << ", ";
            }
            
        }
        if (!this->stackArr[i]->isEmpty()){
            outputFile << this->stackArr[i]->pop();
        }
        outputFile << " inches.\n";
    }
    outputFile.close();
}