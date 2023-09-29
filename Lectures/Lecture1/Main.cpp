#include "TextAnalyzer.h"
#include <iostream>

int main(){
    std::string s = "how many vowels do I have???";
    TextAnalyzer ta; // creating this obj on the stack
    std::cout << "the number of vowels is: " << ta.countVowels(s) << std::endl;
    
    TextAnalyzer* taPtr = new TextAnalyzer();
    std::cout << "the number of vowels is: " << taPtr->countVowels(s) << std::endl;

    delete taPtr;
    return 0;
}