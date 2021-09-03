#include<iostream>
class Binary_Search_Tree{
    public:
        Binary_Search_Tree();
        Binary_Search_Tree(int data);
        Binary_Search_Tree(int* data, int len);
        Binary_Search_Tree* insert(int data);
        Binary_Search_Tree* Delete(int data);
        Binary_Search_Tree* search(int flag);
        int search_ith(int i);
        bool is_search(int data);
        void Inorder();
        void Postorder();
        Binary_Search_Tree* Lchild;
        Binary_Search_Tree* Rchild;
        int lsize=0;
        int data;
    private:

};

Binary_Search_Tree::Binary_Search_Tree(){
    this->data = 0;
    this->Lchild = NULL;
    this->Rchild = NULL;
}

Binary_Search_Tree::Binary_Search_Tree(int data){
    this->data = data;
    this->Lchild = NULL;
    this->Rchild = NULL;
}

Binary_Search_Tree::Binary_Search_Tree(int* data, int len){
    this->data = data[0];
    this->Rchild = NULL;
    this->Lchild = NULL;

    for(int i=1;i<len;i++)
    {
        this->insert(data[i]);
    }
    
}

Binary_Search_Tree* Binary_Search_Tree::insert(int data){
    Binary_Search_Tree* t;

    if(this==NULL)
    {
       t = new Binary_Search_Tree(data);
       return t;
    }

    if(data > this->data)
    {
        this->Rchild = this->Rchild->insert(data);
        t = this;
    }

    if(data < this->data)
    {
        this->Lchild = this->Lchild->insert(data);
        this->lsize++;
        t= this;;
    }
    return t;
    
}

Binary_Search_Tree* Binary_Search_Tree::Delete(int data){
    Binary_Search_Tree* t;
    if(this==NULL)
    {
        return NULL;
    }

    if(data>this->data)
    {
        this->Rchild = this->Rchild->Delete(data);
        return this;
    }

    if(data<this->data)
    {
        this->Lchild = this->Lchild->Delete(data);
        return this;
    }

    if(this->Lchild==NULL && this->Rchild==NULL)
    {
        delete(this);
        return NULL;
    }

    if(this->Lchild!=NULL && this->Rchild==NULL)
    {
        t = this->Lchild;
        delete(this);
        return t;
    }

    if(this->Lchild==NULL && this->Rchild!=NULL)
    {
        t = this->Rchild;
        delete(this);
        return t;
    }

    if(this->Lchild!=NULL && this->Rchild!=NULL)
    {
        Binary_Search_Tree* max = this->Lchild->search(0);
        int max_num = max->data;
        this->Delete(max_num);
        this->data = max_num;
        return  this;
    }
 
}
void Binary_Search_Tree::Inorder(){
    if(this != NULL)
    {
        this->Lchild->Inorder();
        std::cout<<this->data<<"->";
        this->Rchild->Inorder();
    }
}

void Binary_Search_Tree::Postorder()
{
    if(this != NULL)
    {
        this->Lchild->Postorder();
        this->Rchild->Postorder();
        std::cout<<this->data<<"->";
    }
}

Binary_Search_Tree* Binary_Search_Tree::search(int flag){
    if(flag==0){
        if(this!=NULL)
        {
            if(this->Rchild!=NULL)
            {
                return this->Rchild->search(flag);
            }
            else
            {
                return this;
            }
        }
    }

    if(flag==1){
        if(this!=NULL)
        {
            if(this->Lchild!=NULL)
            {
                return this->Lchild->search(flag);
            }
            else
            {
                return this;
            }
        }
        
    }
}

int Binary_Search_Tree::search_ith(int i)
{
    if(this!=NULL)
    {
        if(i-1<this->lsize)
        {
            return this->Lchild->search_ith(i);
        }

        if(i-1>this->lsize)
        {
            return this->Rchild->search_ith(i-this->lsize-1);
        }
        return this->data;
    }
    std::cout<<"out"<<'\n';
}
