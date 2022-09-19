/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* STRING ************* 
class Solution {
public:
    string removeDuplicates(string s) {
        
        string result = "";
        for(int i=0; i<s.length(); i++) {
            if(!result.empty() && result.back()== s[i]) {
                result.pop_back();
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

// ************* STACK ************* 
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> myStack;

        for(int i=0; i<s.length(); i++) {
            
            if(!myStack.empty() && myStack.top() == s[i]) {
                myStack.pop();
            } else {
                myStack.push(s[i]);
            }
        }

        string result = "";
        while(!myStack.empty()) {
            result = myStack.top() + result;
            myStack.pop();
        }

        return result;
    }
};