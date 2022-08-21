/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> pushStack;
    stack<int> popStack;

public:
    MyQueue() {

    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        // if popStack is empty
        // transfer all elements to pop stack
        if(popStack.empty()) {
            while(!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }

        int ans = popStack.top();
        popStack.pop();
        return ans;
    }
    
    int peek() {
        if(popStack.empty()) {
            while(!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        return popStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
};

// ---------- NOT OPTIMIZED ---------
// class MyQueue {
//     stack<int> s;
//     int front;
// public:
//     MyQueue() {
//         this->front = -1;
//     }
    
//     void push(int x) {
//         if(s.empty()) {
//             front = x;
//         }
//         s.push(x);
//     }
    
//     int pop() {
//         int size = s.size() - 1;
//         int temp_size = size;

//         stack<int> temp_s;
//         while(temp_size != 0) {
//             temp_s.push(s.top());
//             s.pop();
//             temp_size--;
//         }

//         int ans = s.top();
//         s.pop();

//         if(!temp_s.empty()) {
//             front = temp_s.top();
//         }
        
//         while(!temp_s.empty()) {
//             s.push(temp_s.top());
//             temp_s.pop();
//         }

//         return ans;
//     }
    
//     int peek() {
//         return front;
//     }
    
//     bool empty() {
//         return s.empty();
//     }
// };

int main() {

    return 0;
}