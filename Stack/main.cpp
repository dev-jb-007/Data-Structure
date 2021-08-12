//
//  main.cpp
//  Stack
//
//  Created by Dev Patel on 03/08/21.
//

#include <iostream>
using namespace::std;
template <class T>
class stack{
private:
    int size;
    int top;
    T* s;
public:
    stack(int n)
    {
        size=n;
        s=new T[size];
        top=-1;
    }
    void push(T val);
    T pop();
    void Display();
    T peek(int index);
    T stackTop();
    bool isEmpty();
    bool isFull();
};
template <class T>
void stack<T>::push(T val)
{
    if(top==size-1)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        s[top]=val;
    }
}
template <class T>
T stack<T>::pop(){
    T x=-1;
    if(top==-1)
    {
        cout<<"No elements left to delete"<<endl;
    }
    else{
        x=s[top];
        top--;
    }
    return x;
}
template <class T>
void stack<T>::Display(){
    for (int i=0; i<=top; i++) {
        cout<<s[top-i]<<endl;
    }
}
template <>
char stack<char>::pop()
{
    char x='-';
    if(top==-1)
    {
        cout<<"No elements left to delete"<<endl;
    }
    else{
        x=s[top];
        top--;
    }
    return x;
}
template <class T>
T stack<T>::peek(int index)
{
    return (top-index+1)<0?-1:s[top-index+1];
}
template <>
char stack<char>::peek(int index)
{
    return (top-index+1)<0?'-':s[top-index+1];
}
template <class T>
T stack<T>::stackTop()
{
    if(top==-1)
    {
        return -1;
    }
    else{
        return s[top];
    }
}
template <>
char stack<char>::stackTop(){
    if(top==-1)
    {
        return '-';
    }
    else{
        return s[top];
    }
}
template <class T>
bool stack<T>::isEmpty(){
    if(top==-1)
    {
        return 1;
    }
    return 0;
}
template <class T>
bool stack<T>::isFull(){
    if(top==(size-1))
    {
        return 1;
    }
    return (0);
}
int main(int argc, const char * argv[]) {
    stack<char> s(4);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
//    cout<<s.pop()<<endl;
//    cout<<s.pop()<<endl;
//    cout<<s.pop()<<endl;
//    cout<<s.pop()<<endl;
//    cout<<s.pop()<<endl;
    s.pop();
    s.pop();
    cout<<s.isFull()<<endl;
    cout<<s.isEmpty()<<endl;
    s.Display();
    return 0;
}
