/*******************************************************************
MONOTONICALLY INCREASING STACK
top => greater
...
bottom => smaller
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        // number of operation greater than 
        // length we return an empty string
        if(num.length() <= k) return "0";
        
        // k is 0, no need of removing
        if(k == 0) return num;
        
        string result = "";// result string
        stack<char> s; // char stack
        
        for(int i=0; i<num.length(); i++){
            while(!s.empty() && num[i] < s.top() && k > 0) {
                // if k greater than 0 and our stack is not empty and the upcoming digit,
                // is less than the current top than we will pop the stack top
                k--;
                s.pop();
            }
            
            s.push(num[i]);
            
            // popping preceding zeroes
            if(s.size() == 1 && num[i] == '0') s.pop();
        }
        
        while(k > 0 && !s.empty()) {
            k--;
            s.pop();
        }
        
        // pushing stack top to result string
        while(!s.empty()) {
            result.push_back(s.top()); 
            s.pop();
        }
        
        // reverse the string 
        reverse(result.begin(),result.end()); 
        
        if(result.length() == 0) return "0";
        return result;
    }
};