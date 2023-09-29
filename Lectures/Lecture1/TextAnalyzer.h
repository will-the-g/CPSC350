// header guard
#ifndef TEXT_ANALYZER_H
#define TEXT_ANALYZER_H

#include <string>
class TextAnalyzer {
    public:
        TextAnalyzer(); // default constructor
        ~TextAnalyzer(); // destructor
        int countVowels(std::string str); // method
        
};

#endif
