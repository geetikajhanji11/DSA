/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> myStack;

    for(char ch : s) {

        if(ch == '(' || ch == '[' || ch == '{') {
            myStack.push(ch); 
        } else {
            if(myStack.empty()) return false;
            char top = myStack.top();
            if(ch == ')' && top == '(') myStack.pop(); 
            else if(ch == ']' && top == '[') myStack.pop();
            else if(ch == '}' && top == '{') myStack.pop();
            else return false;
        }
    }
    return myStack.empty();
}

int main() {

    return 0;
}