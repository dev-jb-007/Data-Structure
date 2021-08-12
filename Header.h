//
//  Header.h
//  Data Structure
//
//  Created by Dev Patel on 09/08/21.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */
//Queue-----------------------------------------------------------------------------------
template <class T>
class QueueNode{
public:
    T val;
    QueueNode *next;
};
template <class T>
class Queue{
private:
    QueueNode<T> *first;
    QueueNode<T> *last;
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
    {   first=new QueueNode<T>;
        first->val=val;
        first->next=NULL;
        last=first;
    }
    else{
        QueueNode<T>* t=new QueueNode<T>;
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
        if(first==last)
        {
            QueueNode<T>*t=first;
            first=first->next;
            delete t;
            t=last;
            last=last->next;
        }
        else{
            QueueNode<T>*t=first;
            first=first->next;
            delete t;
        }
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
    return (first==NULL);
}
template <class T>
void Queue<T>::Display(){
    QueueNode<T> *t=first;
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
}

//Stack-----------------------------------------------------------------------------------
template <class T>
class StackNode{
public:
    T val;
    StackNode *next;
};
template <class T>
class Stack{
private:
    StackNode<T> *first;
public:
    Stack()
    {
        first=NULL;
    }
    void push(T data);
    void pop();
    void Display();
    bool empty();
    T peek(int index);
    T top();
};
template <class T>
void Stack<T>::push(T data)
{   StackNode<T> *t=new StackNode<T>;
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
T Stack<T>::top(){
    return (first)?first->val:NULL;
}
template <class T>
void Stack<T>::pop(){
    if(!first)
    {
        cout<<"No Nodes left to delete"<<endl;
    }
    else{
        StackNode<T> *p=first;
        first=first->next;
        delete p;
    }
}
template <class T>
void Stack<T>::Display(){
    StackNode<T> *p=first;
    while(p)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
}
template <class T>
bool Stack<T>::empty(){
    if(!first)
    {
        return 1;
    }
    else return 0;
}
template <class T>
T Stack<T>::peek(int index)
{
    StackNode<T> *p=first;
    while(index--&&p)
    {
        p=p->next;
    }
    return p?p->val:NULL;
}

