#ifndef STACK_LINK_LIST_H
#define STACK_LINK_LIST_H
template <class T>
struct Node{
    T Data;
    Node* Next;
};
template <class T>
class stack{
    public:
        stack();
        void push(T item);
        T pop();
        bool Isempty();
        T getTop();
    private:
        Node<T>* Top;
};
#include "stack_link_list.cpp"
#endif