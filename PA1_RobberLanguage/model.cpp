#include "model.h"
#include <string>
using namespace std;
model::model(){  
}

model::~model(){
}

string model::translateSingleConsonant(char consonant){
    string str = string(1, consonant);
    return str + "o" + str;
}

string model::translateSingleVowel(char vowel){
    string str = string(1, vowel);
    return str;
}