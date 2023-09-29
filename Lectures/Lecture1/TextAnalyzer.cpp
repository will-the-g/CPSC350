


#include "TextAnalyzer.h"
TextAnalyzer::TextAnalyzer(){
}
TextAnalyzer::~TextAnalyzer(){
}

int TextAnalyzer::countVowels(std::string str){
    int count = 0;
    for (int i = 0; i < str.size(); i++){
        char c = std::tolower(str[i]);
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++count;
            break;
        default:
            break;
        }
    }
    return count;

}