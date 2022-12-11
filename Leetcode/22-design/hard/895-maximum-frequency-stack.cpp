/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class FreqStack {

    int maxFreq;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> stacks;

public:

    FreqStack() {
        this->maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        if(freq[val] > maxFreq) {
            maxFreq = freq[val];
        }
        stacks[freq[val]].push(val);
    }
    
    int pop() {
        int val = stacks[maxFreq].top(); stacks[maxFreq].pop();
        freq[val]--;
        if(stacks[maxFreq].empty()) {
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */