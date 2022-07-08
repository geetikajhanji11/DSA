/**************************************************************

BALANCED PARANTHESIS

Given an expression string, write a program to check all
the pairs of parenthesis are valid.

**************************************************************/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isBalanced(string str) {

    stack<char> s;

    for(char ch : str) {
        
        if(ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } 
        
        else if(ch == ')' || ch == ']' || ch == '}') {

            if(s.empty()) return false;
            char top = s.top();    

            if(ch == ')' && top == '(') s.pop();
            else if(ch ==']' && top == '[') s.pop();
            else if(ch == '}' && top == '{') s.pop();
            
        }
    }

    return s.empty();
}

int main() {

    string str = "[h+(g(f+s))]";

    if(isBalanced(str)) {
        cout<<"Balanced.";
    } else {
        cout<<"Not balanced.";
    }


	return 0;
}