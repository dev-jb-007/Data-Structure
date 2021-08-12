#include<iostream>
using namespace std;
#include "Header.h"
int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    q.pop();
    cout<<q.empty();
}
