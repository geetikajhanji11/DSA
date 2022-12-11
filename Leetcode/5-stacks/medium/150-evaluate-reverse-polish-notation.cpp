/*******************************************************************
Evaluate RPN, valid operators: +, -, *, /

Stack, if num push, if operator apply to top 2 nums

Time: O(n)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int calculate(int first, int second, string operation) {
    if(operation == "+") return first + second;
    else if(operation == "-") return first - second;
    else if(operation == "*") return first * second;
    else return first / second;
}

int evalRPN(vector<string>& tokens) {

    stack<int> stck;

    for(string token : tokens) {
        
        if(token.size() > 1 || isdigit(token[0])) {
            stck.push(stoi(token));
        } 
        
        else {
            string operation = token;
            int second = stck.top();
            stck.pop();
            int first = stck.top();
            stck.pop();

            int ans = calculate(first, second, operation);
            stck.push(ans);
        }
    }

    int result = stck.top();
    stck.pop();

    return result;

}

int main() {


    vector<string> tokens = {"4","13","5","/","+"};
    int ans = evalRPN(tokens);
    cout<<"\nans = "<<ans;
    return 0;
}