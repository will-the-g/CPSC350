#include "NaiveCharStack.h"

NaiveCharStack::NaiveCharStack(int iSize){
    stackArr = new char[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;

}
NaiveCharStack::~NaiveCharStack(){
    delete[] stackArr;

}

bool NaiveCharStack::isEmpty(){
    return (count == 0);
}

bool NaiveCharStack::isFull(){
    return (count == 0);
}

int NaiveCharStack::size(){
    return (count);
}

void NaiveCharStack::push(char c){
    if (isFull()){
        //create temp arr
        char* temp = new char[2*maxSize];
        // copy over elements
        for (int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;

    }
    stackArr[++top] = c;
    ++count;
}
char NaiveCharStack::pop(){
    // check if isEmpty()

    --count;
    return stackArr[top--]; // return stackArr[top] then -- from top
}

char NaiveCharStack::peak(){
    return stackArr[top];
}
