#include "PalindromeFinder.h"

PalindromeFinder::PalindromeFinder(){

}

PalindromeFinder::~PalindromeFinder(){

}

void PalindromeFinder::findPalindromes(DNASeq* input){
    // Checks if string is a valid DNA seqeuence
    if (!input->isValid()){
        cout << input->toString() << " - INVALID" << endl;
        return;
    }
    // checks if the full strand is a palindrome
    if (input->isGeneticPalindrome()){
        cout << input->toString() << " - Genetic Palindrome" << endl;
    }else{
        cout << input->toString() << " - Not a Genetic Palindrome" << endl;
    }
    // checks all the substrings
    int size = input->getSize();
    for (int j = 0; j < size - 5; j++){
        for (int i = j + 5; i < size; i++){
            DblList<char> subList = input->substring(j , i); // creates substrings of the every possible string > 4.
            DNASeq* sub = new DNASeq(subList); // converts to from doubly linked list to DNA Sequence
            if (sub->isGeneticPalindrome()){
                cout << " Substring " << sub->toString() << " - Genetic Palindrome" << endl; 
            }
        }
    }
}