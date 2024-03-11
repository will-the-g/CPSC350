#include "DNASeq.h"


DNASeq::DNASeq(){ 
}

DNASeq::~DNASeq(){
}

// constructor for string to DNA Sequence
DNASeq::DNASeq(string charSequence){
    // converts string to doubly linked list member variable
    this->sequence = DblList<char>();
    this->size = charSequence.length();
    for (int i = 0; i < this->size; i++){
        // Loops through the string and puts each char into the doubly linked list
        this->sequence.addBack(charSequence.at(i));
    }
}

// constructor for converting doubly linked list to DNA Sequences
DNASeq::DNASeq(DblList<char> seq){
    this->sequence = seq;
    this->size = seq.size();
}

// finds the complement of the strand
DblList<char> DNASeq::complement(){
    DblList<char> complementSeq = DblList<char>();
    for (int i = 0; i < this->size; i++){
        // starts at the back and loops to the front
        switch(this->sequence.get(size - (i + 1))){
            case 'T':
                complementSeq.addBack('A');
                break;
            case 'A':
                complementSeq.addBack('T');
                break;
            case 'C':
                complementSeq.addBack('G');
                break;
            case 'G':
                complementSeq.addBack('C');
                break;
        }
    }
    return complementSeq;
}

// creates substring in the form of a DblList from position s to e
DblList<char> DNASeq::substring(int s, int e){
    DblList<char> TheeSubstring = DblList<char>();
    for (int i = s; i < e; i++){
        TheeSubstring.addBack(this->sequence.get(i));
    }
    return TheeSubstring;
}

// checks if the strand is a palindrome
bool DNASeq::isGeneticPalindrome(){    
    int count = 0;
    DblList<char> comp = complement();
    // loops through sequence and its compliment, comparing each position
    for (int i = 0; i < this->size; i++){
        if (this->sequence.get(i) == comp.get(i)){
            count += 1;
        }
    }
    return count == this->size;
}

// size accessor
int DNASeq::getSize(){
    return this->size;
}

// converts the DNA seqeunce to a string
string DNASeq::toString(){
    string str = "";
    for (int i = 0; i < this->size; i++){
        str += this->sequence.get(i);
    }
    return str;
}

// checks if the DNA sequence is a valid sequence
bool DNASeq::isValid(){
    for (int i = 0; i < this->size; i++){
        if (this->sequence.get(i) != 'A' & this->sequence.get(i) != 'T' & this->sequence.get(i) != 'G' & this->sequence.get(i) != 'C'){
            return false;
        }
    }
    return true;
}
