// templated class for a very naive queue implemented w an array

#ifndef AQUEUE_H
#define AQUEUE_H

template <typename T>
// T is the generic data type that will the get replaced with the actual data type at object creation

class AQueue{
    public:
        AQueue(int s);
        ~AQueue();
        void add(T data); // add to the back of queue
        T remove(); // removing & returning the element sitting at the front of queue
        T peek(); // return the element that was first added/ added the earliest/ sitting at the front
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* arr;
        int maxSize; // size of the array
        int front; // index for front element
        int back; // index for back element
        int count; // how many elements are actually in the queue


};

template <typename T>
AQueue<T>::AQueue(int s){
   maxSize = s;
   front = 0;
   back = -1;
   count = 0;
   arr = new T[maxSize]; 
}

template <typename T>
AQueue<T>::~AQueue(){
    delete[] arr;
}


template <typename T>
bool AQueue<T>::isFull(){
    return (count == maxSize);
}


template <typename T>
bool AQueue<T>::isEmpty(){
    return (count == 0);
}


template <typename T>
int AQueue<T>::size(){
    return count;
}


template <typename T>
void AQueue<T>::add(T data){
    if (isFull()){
        return;
    }
    arr[++back] = data;
    ++count;
}



template <typename T>
T AQueue<T>::remove(){
    T ret = arr[front];
    ++front;
    --count;
    return ret;
}