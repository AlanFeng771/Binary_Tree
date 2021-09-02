#include<iostream>
#include "queue_link_list.h"
using namespace std;
template<class T>
queue<T>::queue(){
    front = NULL;
    rear = NULL;
}
template<class T>
void queue<T>::Enqueue(T item){
    Node<T>* t = new Node<T>;
    t->Data = item;
    t->next = NULL;
    if(front==NULL) 
        front = t;
    else
        rear->next = t;
    rear = t;
}
template<class T>
T queue<T>::Dequeue(){
    if(front==NULL){
        string msg = "q is empty";
        throw msg;
    }else{
        Node<T>* t = front;
        T temp = front->Data;
        front = front->next;
        delete t;
        return temp;
    }
    
}
template<class T>
bool queue<T>::Isempty(){
    if(front==NULL){
        return true;
    }else{
        return false;
    }
}
