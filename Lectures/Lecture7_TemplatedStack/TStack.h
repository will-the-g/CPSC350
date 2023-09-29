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

#ifndef T_STACK_H
#define T_STACK_H
#include <iostream> 

template <typename T>
class TStack{
    public:
        TStack(int iSize);
        ~TStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};


template <typename T>
TStack<T>::TStack(int iSize){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
}
template <typename T>
TStack<T>::~TStack(){
    std::cout << "clearing a TStack obj!" << std::endl;
    delete[] stackArr;
}
template <typename T>
bool TStack<T>::isFull(){
    return (count == maxSize);
}
template <typename T>
bool TStack<T>::isEmpty(){
    return (count == 0);
}
template <typename T>
int TStack<T>::size(){
    return count;
}
template <typename T>
void TStack<T>::push(T c){
    if(isFull()){
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    stackArr[++top] = c;
    ++count;
}
template <typename T>
T TStack<T>::pop(){
    --count;
    return stackArr[top--];
}
template <typename T>
T TStack<T>::peek(){
    return stackArr[top];
}
#endif