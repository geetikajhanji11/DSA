/*******************************************************************
"((()()))()(())"
11
*******************************************************************/

#include<iostream> 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<string> myStack;

        for(char ch : s) {

            if(ch == '(') {
                myStack.push("(");
            } 
            
            else {
                if(myStack.top() == "(") {
                    myStack.pop();
                    myStack.push("1");
                } else {
                    int totalSum = 0;
                    while(myStack.top() != "(") {
                        totalSum += stoi(myStack.top());
                        myStack.pop();
                    }
                    myStack.pop();
                    myStack.push(to_string(totalSum * 2));
                }
            }
        }

        int result = 0;

        while(!myStack.empty()) {
            result += stoi(myStack.top());
            myStack.pop();
        }

        return result;
    }
};