#ifndef DNA_SEQ_H
#define DNA_SEQ_H
#include <string>
#include <iostream>
#include "DblList.h"
using namespace std;

class DNASeq{
    public:
        DNASeq();
        ~DNASeq();
        DNASeq(string chars);
        DNASeq(DblList<char> seq);
        DblList<char> complement();
        DblList<char> substring(int s, int e);
        bool isGeneticPalindrome();
        int getSize();
        string toString();
        bool isValid();

    private:
        DblList<char> sequence;
        int size;

};








#endif