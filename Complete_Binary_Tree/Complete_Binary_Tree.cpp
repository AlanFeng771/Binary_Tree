#include<iostream>
#include "../Binary_Tree.h"
#include "../queue/queue_link_list.h"
using namespace std;
template<class T>
class Complete_Binary_Tree :public Binary_Tree<T>{
    public:
        Complete_Binary_Tree();
        Complete_Binary_Tree(T data);
        Complete_Binary_Tree(T* Tree, int len);
        void Leavel_order();
};
int main(){
    Complete_Binary_Tree<int> bt = Complete_Binary_Tree<int>(10);
    bt.addLchild(20);
    bt.addRchild(30);
    bt.Inorder();
    cout<<endl;
    bt.Postorder();
    cout<<endl;
    int a[] = {1, 2, 3};
    Complete_Binary_Tree<int> bt1 = Complete_Binary_Tree<int>(a, 3);
    bt1.Inorder();
    cout<<endl;
    bt1.Postorder();
    cout<<endl;
    bt1.Leavel_order();
}
template<class T>
Complete_Binary_Tree<T>::Complete_Binary_Tree(){

}
template<class T>
Complete_Binary_Tree<T>::Complete_Binary_Tree(T data):Binary_Tree<T>(data){

}
template<class T>
Complete_Binary_Tree<T>::Complete_Binary_Tree(T* tree, int len){
    queue<Complete_Binary_Tree<T>*> q;
    Complete_Binary_Tree<T>* root = NULL;
    Complete_Binary_Tree<T>* rchild;
    Complete_Binary_Tree<T>* lchild;
    int index = 1;
    while(true){
        if(index == len+1){
            break;
        }
        if(root == NULL){
            root = this;
        }else{
            root = q.Dequeue();
        }
        root->data = tree[index-1];
        if(index*2>=len+1){
            root->Lchild = NULL;
            root->Rchild = NULL;
        }else if(index*2<len+1 && index*2+1>=len+1){
            lchild = new Complete_Binary_Tree();
            root->Lchild = lchild;
            root->Rchild = NULL;
            q.Enqueue(lchild);
        }else{
            lchild = new Complete_Binary_Tree();
            rchild = new Complete_Binary_Tree();
            root->Lchild = lchild;
            root->Rchild = rchild;
            q.Enqueue(lchild);
            q.Enqueue(rchild);
        }
        index++;
    }
}
template<class T>
void Complete_Binary_Tree<T>::Leavel_order(){
    queue<Binary_Tree<T>*> q;
    Binary_Tree<T>* root=NULL;
    do{
        if(root==NULL){
            root = this;
        }else{
            root = q.Dequeue();
        }
        cout<<root->data<<"->";
        q.Enqueue(root->Lchild);
        q.Enqueue(root->Rchild);

    }while(root!=NULL);
}
