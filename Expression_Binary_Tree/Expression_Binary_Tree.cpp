#include<iostream>
#include"../Binary_Tree.h"
#include"../stack/stack_link_list.h"
#include<cmath>
using namespace std;
class Expression_Binary_Tree : public Binary_Tree<char>{
    public:
        Expression_Binary_Tree();
        Expression_Binary_Tree(char data);
        Expression_Binary_Tree(string Tree);
        Expression_Binary_Tree* Lchild;
        Expression_Binary_Tree* Rchild;
        void Inorder();
        char data;
        void Eval();
        int res=0;
};
bool is_operand(char c){
    return ((int)c>=97 && (int)c<=122)||((int)c>=48 && (int)c<=57);
}


Expression_Binary_Tree::Expression_Binary_Tree():Binary_Tree<char>(){

}

Expression_Binary_Tree::Expression_Binary_Tree(char data){
    this->data = data;
    this->Lchild = NULL;
    this->Rchild = NULL;
}

Expression_Binary_Tree::Expression_Binary_Tree(string Tree){
    stack<Expression_Binary_Tree*> s;
    Expression_Binary_Tree* node;
    for(int i=0;i<Tree.size();i++){
      if(is_operand(Tree[i])){
        node = new Expression_Binary_Tree(Tree[i]);
        //cout<<"operand "<<node->data<<endl;
        s.push(node);
      }else{
        if(i==Tree.size()-1){
            node = this;
            node->data = Tree[i];
            //cout<<"this "<<node->data<<endl;
        }

        else{
            node = new Expression_Binary_Tree(Tree[i]);
            //cout<<"orther "<<node->data<<endl;
        }
        
        node->Rchild = s.pop();
        node->Lchild = s.pop();
        s.push(node);
      }
    }
    
}

void Expression_Binary_Tree::Eval(){
    if(this!=NULL){
        this->Lchild->Eval();
        this->Rchild->Eval();
        //cout<<this->data<<endl;
        if(is_operand(this->data)){
            this->res = ((int)this->data)-48;
            
        }

        else{
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
    // cout<<"NULL"<<endl;
}
void Expression_Binary_Tree::Inorder(){
    if(this!=NULL){
        this->Lchild->Inorder();
        cout<<this->data<<"->";
        this->Rchild->Inorder();
    }
}
