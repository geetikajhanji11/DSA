/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<int> standard_stack;
    stack<int> min_stack;

    MinStack() {
        
    }
    
    void push(int val) {
        standard_stack.push(val);
        if(!min_stack.empty() && val <= min_stack.top()) {
            min_stack.push(val);
        }
        else if(min_stack.empty()) min_stack.push(val);
    }
    
    void pop() {
        int val = standard_stack.top();
        if(val == min_stack.top()) min_stack.pop();
        standard_stack.pop();
    }
    
    int top() {
        return standard_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main() {

    return 0;
}