#include<iostream>
#include<string>
#include "stack_link_list.h"
using namespace std;
template <class T>
stack<T>::stack(){
    Top = NULL;
}
template <class T>
void stack<T>::push(T item){
    Node<T>* t = new Node<T>;
    t->Next = Top;
    t->Data = item;
    Top = t;
}
template <class T>
T stack<T>::pop(){
    T temp;
    string msg = "s is empty";
    if(Top==NULL)
        throw msg;
    else{
        Node<T>* t = Top;
        temp = Top->Data;
        Top = Top->Next;
        delete t;
    }
    return temp;
}
template <class T>
bool stack<T>::Isempty(){
    if(Top==NULL){
        return true;
    }else{
        return false;
    }

}
template <class T>
T stack<T>::getTop(){
    if(Top==NULL){
        string str = "s is empty";
        throw str;
    }else{
        return Top->Data;
    }
}