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
#include "DblList.h"

class ListStack{
    public:
        ListStack();
        ~ListStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isEmpty();
        int size();

    private:
        DblList* stackList;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};

template <typename T>
ListStack<T>::ListStack(){
    DblList stackList = new DblList();
}
template <typename T>
ListStack<T>::~ListStack(){
    delete stackList;
}

template <typename T>
bool ListStack<T>::isEmpty(){
    return (stackList->isEmpty());
}
template <typename T>
int ListStack<T>::size(){
    return stackList->size();
}
template <typename T>
void ListStack<T>::push(T c){
    stackList->addBack(c);
}
template <typename T>
T ListStack<T>::pop(){
    return stackList->removeBack();
}
template <typename T>
T ListStack<T>::peek(){
    return stackList->get(stackList->size() - 1);
}

#endif