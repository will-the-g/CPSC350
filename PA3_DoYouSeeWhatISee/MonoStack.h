/*
    templated class for a stack 
    we can now create a stack that can hold any 
    type of object and not just specific to one data type 
    (like our naive char stack)

    templated classes are defined AND implemented in a 
    header file! Why? 
*/
/*
    templated class bc we don't want to manually create
    several different versions of the same class just 
    to be able to hold different objects/ data types 
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <iostream> 

template <typename T>
class MonoStack{
    public:
        MonoStack(int iSize, bool stackType);
        ~MonoStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int getSize();

    private:
        T* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
        bool stackType; //True = decreasing, False = increasing
};


template <typename T>
MonoStack<T>::MonoStack(int iSize, bool stackType){
    this->stackType = stackType;
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
}
template <typename T>
MonoStack<T>::~MonoStack(){
    delete[] stackArr;
}
template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
}
template <typename T>
int MonoStack<T>::getSize(){
    return count;
}
template <typename T>
void MonoStack<T>::push(T c){
    if(isFull()){
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    if (this->stackType & !isEmpty()){
        while(peek() < c & !isEmpty()){ // stackType is True, then pops all values less than c
            pop();
        }
    }else if (!this->stackType & !isEmpty()){
        while(peek() > c & !isEmpty()){ // stackType is False, then pops all values greater than c
            pop();
        }
    }
    stackArr[++top] = c;
    ++count;
}
template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
}
template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top];
}
#endif