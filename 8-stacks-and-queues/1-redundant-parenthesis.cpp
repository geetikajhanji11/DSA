/**************************************************************

REDUNDANT PARANTHESIS

Given a string of balanced expression, find if it contains a
redundant parenthesis or not. A set of parenthesis are 
redundant if same sub-expression is surrounded by unnecessary
or multiple brackets. Print "YES" if redundant else "NO".

**************************************************************/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isRedundant(string str) {

    stack<char> s;

    for(char ch : str) {
        
        if(ch == ')' || ch == ']' || ch == '}') {

            bool isOperatorPresent = false;
            char open;
            if(ch == ')') open = '('; 
            else if(ch == ']') open = '['; 
            else if(ch == '}') open = '{'; 

            // check if operator is present in between brackets
            char top = s.top();
            while(top != open) {
                if(top == '+' || top == '-' || top == '*' || top == '/') {
                    isOperatorPresent = true;
                }
                s.pop();
                top = s.top();
            }

            // pop opening bracket
            s.pop(); 

            if(!isOperatorPresent) {
                return true;
            }
    
        }

        // push all characters other than closing brackets
        s.push(ch);
    }

    return false;
}

int main() {

    string str = "((a+(b))+c)";

    if(isRedundant(str)) {
        cout<<"REDUNDANT";
    } else {
        cout<<"NOT REDUNDANT";
    }


	return 0;
}