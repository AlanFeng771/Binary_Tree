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
bool Isoperand(char c){
    return ((int)c>=97 && (int)c<=122)||((int)c>=48 && (int)c<=57);
}
int main(){
    string str = "2222***22+/";
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
    stack<Expression_Binary_Tree<T>*> s_operand;
    stack<Expression_Binary_Tree<T>*> s_opertor;
    Expression_Binary_Tree<char>* root=NULL;
    Expression_Binary_Tree<char>* n;
    bool flag = true;
    for(int i=0;i<Tree.size();i++){
        char x = Tree[i];
        if(Isoperand(x)){
            n = new Expression_Binary_Tree<char>(x);
            if(s_operand.Isempty()){
                flag = true;
            }
            s_operand.push(n);
            //cout<<"In operand data:"<<x<<endl;
        }else{
            if(i==Tree.size()-1){
                root = this;
                this->data = x;
            }else
                root = new Expression_Binary_Tree(x);
            if(flag){
                if(!s_operand.Isempty()){
                    root->Rchild = s_operand.pop();
                    root->Lchild = s_operand.pop();
                    s_opertor.push(root);
                    flag = false;
                    //cout<<"In opertor 1 data:"<<x<<endl;
                }
            }else{
                if(!s_operand.Isempty()){
                    root->Lchild = s_operand.pop();
                    root->Rchild = s_opertor.pop();
                    s_opertor.push(root);
                    //cout<<"In opertor 2 data:"<<x<<endl;
                }else{
                    root->Rchild = s_opertor.pop();
                    root->Lchild = s_opertor.pop();
                    s_opertor.push(root);
                    //cout<<"In opertor 3 data:"<<x<<endl;
                }
            }
        }
    }
}
// template<class T>
// void Expression_Binary_Tree<T>::Eval(){
//     if(this!=NULL){
//         this->Lchild->Eval();
//         this->Rchild->Eval();
//         if(Isoperand(this->data)){
//             this->res = ((int)this->data)-48;
//         }else{
//             switch (this->data)
//             {
//             case '+':
//                 this->res = (this->Lchild)->res + (this->Rchild)->res;
//                 break;
//             case '-':
//                 this->res = (this->Lchild)->res - (this->Rchild)->res;
//                 break;
//             case '*':
//                 this->res = (this->Lchild)->res * (this->Rchild)->res;
//                 break;
//             case '/':
//                 this->res = (this->Lchild)->res / (this->Rchild)->res;
//                 break;
//             case '^':
//                 this->res = (int)pow((float)(this->Lchild)->res, (float)(this->Rchild)->res);
//                 break;
//             default:
//                 break;
//             }
            
//         }
//     }
// }