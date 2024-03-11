#include "translator.h"
#include "model.cpp"
using namespace std;
translator::translator(){
}
translator::~translator(){
}
string translator::translateEnglishWord(string englishWord){
    model model1;
    string output = "";
    for (int i = 0; i < englishWord.size(); i++){
        char letter = tolower(englishWord[i]);
        if (letter != 'a' && letter != 'e'  && letter != 'i' && letter != 'o' && letter != 'u' && isalpha(letter)){
            output += model1.translateSingleConsonant(englishWord[i]);
        }else if (isalpha(letter)){
            output += model1.translateSingleVowel(englishWord[i]);
        }
    }
    return output;
}
string translator::translateEnglishSentence(string englishSentence){

    string output = "";
    for (int i = 0; i < englishSentence.size(); i++){
        if (isalpha(englishSentence[i]) == false){
            output += translateEnglishWord(englishSentence.substr(0, i));
            englishSentence.erase(0, i);
            output += englishSentence[0];
            englishSentence.erase(0,1);
            i = 0;
        } else if(i == englishSentence.size()){
            output += translateEnglishWord(englishSentence.substr(0, i + 1));
        }
    }
    return output;
}