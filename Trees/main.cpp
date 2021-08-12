//
//  main.cpp
//  Trees
//
//  Created by Dev Patel on 09/08/21.
//

#include <iostream>
using namespace std;
#include "../Header.h"
template <class T>
class TreeNode{
public:
    T val;
    TreeNode *left;
    TreeNode *right;
};template <class T>
class Tree{

public:
    TreeNode<T> *root;
    Queue<TreeNode<T>*> q;
    Tree();
    void Create();
    void Preorder(TreeNode<T> *t);
    void Inorder(TreeNode<T> *t);
    void Postorder(TreeNode<T> *t);
    void ItrPreorder(TreeNode<T> *t);
    void ItrInorder(TreeNode<T> *t);
    void ItrPostorder(TreeNode<T> *t);
    void LeverOrder(TreeNode<T> *t);
    int TotalNodes(TreeNode<T> *t);
    int LeafNodes(TreeNode<T> *t);
    int NonLeafNodes(TreeNode<T> *t);
    int LeftChildNodes(TreeNode<T> *t);
    int RightChildNodes(TreeNode<T> *t);
    int height(TreeNode<T> *t);
};
template <class T>
Tree<T>::Tree(){
    root=NULL;
}
template <class T>
void Tree<T>::Create(){
    int val;
    root=new TreeNode<T>;
    root->left=NULL;
    root->right=NULL;
    TreeNode<T> *t,*p;
    cout<<"Enter the value of the root node:";
    cin>>root->val;
    q.push(root);
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        cout<<"Enter the value of left child of "<<p->val<<" node:";
        cin>>val;
        if(val!=-1)
        {
            t=new TreeNode<T>;
            t->val=val;
            t->left=NULL;
            t->right=NULL;
            q.push(t);
            p->left=t;
        }
        cout<<"Enter the value of Right child "<<p->val<<" node:";
        cin>>val;
        if(val!=-1)
        {
            t=new TreeNode<T>;
            t->val=val;
            t->left=NULL;
            t->right=NULL;
            q.push(t);
            p->right=t;
        }
    }
}
template <class T>
void Tree<T>::Preorder(TreeNode<T>*p){
    if(p)
    {
        cout<<p->val;
        Preorder(p->left);
        Preorder(p->right);
    }
}
template <class T>
void Tree<T>::Inorder(TreeNode<T>*p){
    if(p)
    {
        Inorder(p->left);
        cout<<p->val;
        Inorder(p->right);
    }
}
template <class T>
void Tree<T>::Postorder(TreeNode<T>*p){
    if(p)
    {
        Postorder(p->left);
        Postorder(p->right);
        cout<<p->val;
    }
}
template <class T>
void Tree<T>::ItrPreorder(TreeNode<T> * t)
{
    Stack<TreeNode<T>*> s;
    while(t!=NULL||!s.empty())
    {
        if(t!=NULL)
        {
            cout<<t->val;
            s.push(t);
            t=t->left;
        }
        else{
            t=s.top();
            s.pop();
            t=t->right;
        }
    }
}
template <class T>
void Tree<T>::ItrInorder(TreeNode<T> *t)
{
    Stack<TreeNode<T> *>s;
    while(t!=NULL||!s.empty())
    {
        if(t!=NULL)
        {
            s.push(t);
            t=t->left;
        }
        else{
            t=s.top();
            s.pop();
            cout<<t->val;
            t=t->right;
        }
    }
}
template <class T>
void Tree<T>::LeverOrder(TreeNode<T> *t)
{
    Queue<TreeNode<T>*> q;
    cout<<t->val;
    q.push(t);
    while(!q.empty())
    {
        t=q.top();
        q.pop();
        if(t->left)
        {
            cout<<t->left->val;
            q.push(t->left);
        }
        if(t->right)
        {
            cout<<t->right->val;
            q.push(t->right);
        }
    }
}
template <class T>
int Tree<T>::TotalNodes(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=count(t->left);
        y=count(t->right);
        return x+y+1;
    }
    return 0;
}
template <class T>
int Tree<T>::LeafNodes(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=LeafNodes(t->left);
        y=LeafNodes(t->right);
        if(!t->left&&!t->right)
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
template <class T>
int Tree<T>::NonLeafNodes(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=NonLeafNodes(t->left);
        y=NonLeafNodes(t->right);
        if(t->left&&t->right)
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
template <class T>
int Tree<T>::LeftChildNodes(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=LeftChildNodes(t->left);
        y=LeftChildNodes(t->right);
        if(t->left&&!t->right)
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
template <class T>
int Tree<T>::RightChildNodes(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=RightChildNodes(t->left);
        y=RightChildNodes(t->right);
        if(t->right&&!t->left)
        {
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}
template <class T>
int Tree<T>::height(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=height(t->left);
        y=height(t->right);
        if(x>y)
        {
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    Tree<int> t;
    t.Create();
    t.LeverOrder(t.root);
//    cout<<endl<<t.LeafNodes(t.root);
//    cout<<endl<<t.NonLeafNodes(t.root);
//    cout<<endl<<t.LeftChildNodes(t.root);
//    cout<<endl<<t.RightChildNodes(t.root);
    cout<<endl<<t.height(t.root);
//    cout<<endl;
//    t.ItrPreorder(t.root);
//    cout<<endl;
//    t.Inorder(t.root);
//    cout<<endl;
//    t.ItrInorder(t.root);
//    cout<<endl;
//    t.Postorder(t.root);
//    cout<<endl;
//    t.ItrPostorder(t.root);
//    cout<<endl;
//    t.Inorder(t.root);
//    cout<<endl;
//    t.Postorder(t.root);
    return 0;
}
