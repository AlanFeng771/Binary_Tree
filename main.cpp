#include <iostream>
#include "./Binary_Search_Tree/Binary_Search_Tree.cpp"
int main(){
    int a[] = {20, 60, 5, 80, 6};
    Binary_Search_Tree bt = Binary_Search_Tree(a, 5);
    std::cout<<bt.data<<'\n';
    bt.Inorder();
    std::cout<<'\n';
    bt.Postorder();
    std::cout<<'\n';
    bt.Delete(6);
    bt.Inorder();
    std::cout<<'\n';
    bt.Postorder();
    std::cout<<'\n';
    std::cout<<bt.search_ith(1);

}