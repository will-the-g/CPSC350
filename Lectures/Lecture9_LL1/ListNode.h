#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>


template<typename T>
class ListNode{
    public:
        ListNode(T data);
        ~ListNode();
        T m_data;
        // recursive data structure bc we are referencing objects of its own type
        ListNode<T>* m_next;
        ListNode<T>* m_prev;
};

template<typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_prev = NULL;
}

template<typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}

#endif