#include<iostream>
#include "Binary_Tree.h"
using namespace std;
int main(){
    Binary_Tree<int> bt = Binary_Tree<int>(10);
    bt.addLchild(20);
    bt.addRchild(30);
    bt.Inorder();
    cout<<endl;
    bt.Postorder();
}