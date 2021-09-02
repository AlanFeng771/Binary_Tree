#ifndef QUEUE_LINK_LIST_H
#define QUEUE_LINK_LIST_H
template<class T>
struct Node{
    T Data;
    Node<T>* next;
};
template<class T>
class queue{
    public:
        queue();
        bool Isempty();
        void Enqueue(T item);
        T Dequeue();
    private:
        Node<T>* front;
        Node<T>* rear;
        
};
#include "queue_link_list.cpp"
#endif
