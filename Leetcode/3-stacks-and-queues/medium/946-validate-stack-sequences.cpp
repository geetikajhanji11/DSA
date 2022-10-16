/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;

        s.push(pushed[0]);

        int push_i = 1;
        int pop_i = 0;

        while(!s.empty() && push_i <= pushed.size() && pop_i < popped.size()) {
            
            while(!s.empty() && pop_i < popped.size() && s.top() == popped[pop_i]) {
                s.pop();
                pop_i++;
            }

            if(push_i < pushed.size()) s.push(pushed[push_i]);
            push_i++;
            
        }

        return s.empty();

    }
};