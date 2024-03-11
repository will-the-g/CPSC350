#ifndef TRANSLATOR_H
#define TRANSLATOR_H
using namespace std;
#include <string>
#include "model.h"
class translator{
    public:
        translator();
        ~translator();
        string translateEnglishWord(string englishWord);
        string translateEnglishSentence(string englishSentence);
};

#endif