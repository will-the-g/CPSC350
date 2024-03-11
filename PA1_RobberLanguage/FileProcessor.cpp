#include "FileProcessor.h"

FileProcessor::FileProcessor(){
}
FileProcessor::~FileProcessor(){
}
void FileProcessor::processFile(string input, string output){
    translator translator1;
    fstream outputFile;
    outputFile.open(output, ios::out);
    if(outputFile.is_open()){
        outputFile<<"<!DOCTYPE html>\n"
        "<html>\n"
        "<title>English to Robber Translation</title>\n"
        "</head>\n"
        "<body>\n";
    }
    fstream file;
    file.open(input, ios::in);
    if (file.is_open() && outputFile.is_open()){
        string line;
        while(getline(file, line)){
            outputFile << "<p><b>" + line + "</b><br></p>\n";
        }
        outputFile << "<p><b></b><br></p>";
        file.close();
        file.open(input, ios::in);
        while(getline(file, line)){
            outputFile << "<p><i>" + translator1.translateEnglishSentence(line) + "</i><br></p>\n"; 
        }
        file.close();
        outputFile << "<p><i></i><br></p>\n"
        "</body>\n"
        "</html>";
        outputFile.close();
    }


}