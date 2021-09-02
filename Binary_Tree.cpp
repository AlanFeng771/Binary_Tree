#include<iostream>
using namespace std;
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
        int Count();
        int Height();
        Binary_Tree<T>* Swap();
        Binary_Tree<T>* getLchild();
        Binary_Tree<T>* getRchild();
        T getData();
    private:
        Binary_Tree<T>* Lchild;
        Binary_Tree<T>* Rchild;
        T data;
};
int main(){
    
} 
template<class T>
Binary_Tree<T>::Binary_Tree(T data){
    this->data = data;
    this->Lchild = NULL;
    this->Rchild = NULL;
}
template<class T>
void Binary_Tree<T>::Inorder(){
    if(this!=NULL){
        this->Lchild->Inorder();
        cout<<this->data<<"->";
        this->Rchild->Inorder();
    }
}
template<class T>
void Binary_Tree<T>::Postorder(){
    if(this!=NULL){
        this->Lchild->Postorder();
        this->Rchild->Postorder();
        cout<<this->data<<"->";
    }
}
template<class T>
void Binary_Tree<T>::Preorder(){
    if(this!=NULL){
        cout<<this->data<<"->";
        this->Lchild->Preorder();
        this->Rchild->Preorder();
    }
}
template<class T>
void Binary_Tree<T>::addLchild(T data){
    this->Lchild = new Binary_Tree<T>(data);
}
template<class T>
void Binary_Tree<T>::addRchild(T data){
    this->Rchild = new Binary_Tree<T>(data);
}
template<class T>
Binary_Tree<T>* Binary_Tree<T>::Copy(){
    if(this==NULL){
        return NULL;
    }else{
        Binary_Tree<T>* t = new Binary_Tree(this->data);
        t->Lchild = this->Lchild->Copy();
        t->Rchild = this->Rchild->Copy();
        return t;
    }
}
template<class T>
bool Binary_Tree<T>::Equal(Binary_Tree<T>* Tree){
    bool result = false;
    if(this==NULL && Tree==NULL){
        return true;
    }else if(this!=NULL && Tree!=NULL){
        if(this->data==Tree->data){
            if(this->Lchild->Equal(Tree->Lchild)){
                result =  this->Rchild->Equal(Tree->Rchild);
            }
        }
    }
    return result;
}
template<class T>
int Binary_Tree<T>::Count(){
    if(this==NULL){
        return 0;
    }
    return this->Lchild->Count()+this->Rchild->Count()+1;
}
template<class T>
int Binary_Tree<T>::Height(){
    int lheight;
    int rheight;
    if(this==NULL){
        return 0;
    }else{
        lheight = this->Lchild->Height();
        rheight = this->Rchild->Height();
        return lheight>=rheight?lheight+1:rheight+1;
    } 
}
template<class T>
Binary_Tree<T>* Binary_Tree<T>::Swap(){
    if(this==NULL){
        return NULL;
    }else{
        Binary_Tree<T>* t = this->Lchild->Swap();
        this->Lchild = this->Rchild->Swap();
        this->Rchild = t;
        return this;
    }
}
template<class T>
Binary_Tree<T>* Binary_Tree<T>::getLchild(){
    return this->Lchild;
}
template<class T>
Binary_Tree<T>* Binary_Tree<T>::getRchild(){
    return this->Rchild;
}
template<class T>
T Binary_Tree<T>::getData(){
    return this->data;
}
