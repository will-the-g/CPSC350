#ifndef NAIVE_CHAR_STACK_H
#define NAIVE_CHAR_STACK_H
class NaiveCharStack{
    public:
        NaiveCharStack(int iSize);
        ~NaiveCharStack();

        void push(char c);
        char pop();
        char peak();
        
        bool isFull();
        bool isEmpty();

        int size();
    private:
        char* stackArr;
        int count;
        int maxSize;
        int top; // keeps track of the index for the top
};