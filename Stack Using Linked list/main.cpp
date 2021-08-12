//
//  main.cpp
//  Stack Using Linked list
//
//  Created by Dev Patel on 03/08/21.
//

#include <iostream>
#include<string.h>
using namespace std;
template <class T>
class Node{
public:
    T val;
    Node *next;
};
template <class T>
class stack{
private:
    Node<T> *first;
public:
    stack()
    {
        first=NULL;
    }
    void push(T data);
    void pop();
    void Display();
    bool isEmpty();
    Node<T>* peek(int index);
    T stackTop();
};
template <class T>
void stack<T>::push(T data)
{   Node<T> *t=new Node<T>;
    t->val=data;
    t->next=NULL;
    if(!first)
    {
        first=t;
    }
    else{
        t->next=first;
        first=t;
    }
}
template <class T>
void stack<T>::pop(){
    if(!first)
    {
        cout<<"No Nodes left to delete"<<endl;
    }
    else{
        Node<T> *p=first;
        char x=first->val;
        first=first->next;
        delete p;
    }
}
template <class T>
void stack<T>::Display(){
    Node<T> *p=first;
    while(p)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
}
template <class T>
bool stack<T>::isEmpty(){
    if(!first)
    {
        return 1;
    }
    else return 0;
}
template <class T>
Node<T>* stack<T>::peek(int index)
{   Node<T> *p=first;
    while(index--&&p)
    {
        p=p->next;
    }
    return p;
}
template <>
char stack<char>::stackTop(){
    return (first)?first->val:'-';
}
bool isOperand(char c)
{
    if(c=='*'||c=='/'||c=='+'||c=='-')
    {
        return 0;
    }
    else{
        return 1;
    }
}
int precedence(char c)
{
    if(c=='*'||c=='/')
    {
        return 1;
    }
    else{
        return 0;
    }
}
template <class T>
char * infixToPostfix(char *infix,stack<T> *s)
{   int i=0,j=0;
    char *postfix=new char[strlen(infix)+1];
    while(infix[i])
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(s->peek(0)->val))
            {
                s->push(infix[i]);
                i++;
            }
            else{
                postfix[j++]=s->pop();
            }
        }
    }
    while(s->isEmpty())
    {
        postfix[j++]=s->pop();
    }
    postfix[j]=NULL;
    return postfix;
}
int main(int argc, const char * argv[]) {
    stack<char> s;
    char infix[]="a+b";
    char *postfix;
    postfix=infixToPostfix(infix,&s);
    cout<<postfix<<endl;
    return 0;
}
