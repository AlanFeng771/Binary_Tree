#include<iostream>
#include"../Binary_Tree.h"
#include"../stack/stack_link_list.h"
#include<cmath>
using namespace std;
template<class T>
class Expression_Binary_Tree : public Binary_Tree<T>{
    public:
        Expression_Binary_Tree();
        Expression_Binary_Tree(T data);
        Expression_Binary_Tree(string Tree);
        void Eval();
        int res;
};
bool is_operand(char c){
    return ((int)c>=97 && (int)c<=122)||((int)c>=48 && (int)c<=57);
}
int main(){
    string str = "abcd***ef+/gh+/";
    Expression_Binary_Tree<char> bt = Expression_Binary_Tree<char>(str);
    cout<<bt.Rchild->data<<endl;
    //bt.Eval();
    //cout<<bt.res<<endl;
    bt.Inorder();
    cout<<endl;
    bt.Postorder();
    cout<<endl;
    
}
template<class T>
Expression_Binary_Tree<T>::Expression_Binary_Tree():Binary_Tree<T>(){

}
template<class T>
Expression_Binary_Tree<T>::Expression_Binary_Tree(T data):Binary_Tree<T>(data){

}
template<class T>
Expression_Binary_Tree<T>::Expression_Binary_Tree(string Tree){
    stack<Expression_Binary_Tree<T>*> s;
    Expression_Binary_Tree<T>* node;
    for(int i=0;i<Tree.size();i++){
      if(is_operand(Tree[i])){
        node = new Expression_Binary_Tree<char>(Tree[i]);
        s.push(node);
      }else{
        if(i==Tree.size()-1){
            node = this;
            node->data = Tree[i];
        }

        else{
            node = new Expression_Binary_Tree<char>(Tree[i]);
        }
        
        node->Rchild = s.pop();
        node->Lchild = s.pop();
        s.push(node);
      }
    }
    
}
template<class T>
void Expression_Binary_Tree<T>::Eval(){
    if(this!=NULL){
        this->Lchild->Eval();
        this->Rchild->Eval();
        if(Isoperand(this->data)){
            this->res = ((int)this->data)-48;
        }else{
            switch (this->data)
            {
            case '+':
                this->res = (this->Lchild)->res + (this->Rchild)->res;
                break;
            case '-':
                this->res = (this->Lchild)->res - (this->Rchild)->res;
                break;
            case '*':
                this->res = (this->Lchild)->res * (this->Rchild)->res;
                break;
            case '/':
                this->res = (this->Lchild)->res / (this->Rchild)->res;
                break;
            case '^':
                this->res = (int)pow((float)(this->Lchild)->res, (float)(this->Rchild)->res);
                break;
            default:
                break;
            }
            
        }
    }
}