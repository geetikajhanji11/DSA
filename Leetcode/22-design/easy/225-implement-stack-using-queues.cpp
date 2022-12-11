/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size() - 1;

        while(size != 0) {
            int top = q.front();
            q.pop();
            q.push(top);
            size--;
        }       

        int top = q.front();
        q.pop();

        return top;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {

    return 0;
}