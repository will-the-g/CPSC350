#ifndef PROCESSFILE_H
#define PROCESSFILE_H
using namespace std;
#include <string>
class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string input, string output);
        
};

#endif