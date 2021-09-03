#ifndef BINARY_TREE_H
#define BINARY_TREE_H
template<class T>
class Binary_Tree{
    public:
        Binary_Tree();
        Binary_Tree(T data);
        void Inorder();
        void Postorder();
        void Preorder();
        void addLchild(T data);
        void addRchild(T data);
        Binary_Tree<T>* Copy();
        bool Equal(Binary_Tree<T>* Tree);
        // bool operator==(const Binary_Tree<T>&, const Binary_Tree<T>&);
        int Count();
        int Height();
        Binary_Tree<T>* Swap();
        Binary_Tree<T>* getLchild();
        Binary_Tree<T>* getRchild();
        T getData();
        Binary_Tree<T>* Lchild;
        Binary_Tree<T>* Rchild;
        T data;
    private:
        
};
#include "Binary_Tree.cpp"
#endif