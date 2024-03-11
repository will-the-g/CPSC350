#ifndef MODEL_H
#define MODEL_H
using namespace std;
#include <string>
class model{
    public:
        model();
        ~model();
        string translateSingleConsonant(char consonant);
        string translateSingleVowel(char vowel);

};

#endif