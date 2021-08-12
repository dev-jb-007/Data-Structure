//
//  main.cpp
//  Queue
//
//  Created by Dev Patel on 07/08/21.
//

#include <iostream>
using namespace std;
template <class T>
class Node{
public:
    T val;
    Node *next;
};
template <class T>
class Queue{
private:
    Node<T> *first;
    Node<T> *last;
public:
    Queue();
    void push(T val);
    void pop();
    T top();
    T Last();
    bool empty();
    void Display();
    ~Queue();
};
template <class T>
Queue<T>::Queue(){
    first=last=NULL;
}
template <class T>
void Queue<T>::push(T val)
{
    if(!first)
    {   first=new Node<T>;
        first->val=val;
        first->next=NULL;
        last=first;
    }
    else{
        Node<T>* t=new Node<T>;
        t->val=val;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
template <class T>
void Queue<T>::pop(){
    if(!last)
    {
        cout<<"No value left to pop"<<endl;
    }
    else{
        Node<T>*t=first;
        first=first->next;
        delete t;
    }
}
template <class T>
T Queue<T>::top(){
    return !first?NULL:first->val;
}
template <class T>
T Queue<T>::Last(){
    return !last?NULL:last->val;
}
template <class T>
bool Queue<T>::empty(){
    return (first==last);
}
template <class T>
void Queue<T>::Display(){
    Node<T> *t=first;
    while(t)
    {
        cout<<t->val<<" ";
        t=t->next;
    }
    cout<<endl;
}
template <class T>
Queue<T>::~Queue(){
    delete first;
    delete last;
}
int main(int argc, const char * argv[]) {
    Queue<char> q;
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    cout<<q.Last()<<endl;
    q.Display();
}
