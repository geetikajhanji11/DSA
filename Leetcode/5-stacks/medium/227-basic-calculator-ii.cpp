/*******************************************************************
"1-1+1"
"1-1-1"
"9+3*8/4"
"9+3*2+8/4"
"3+2*2"
" 3/2 "
" 3+5 / 2 "

Add dummy '+' at the end, so that
we don't have to compute the last 
edge case separately after the for
loop ends [2+3*4] 
    state after loop ends: 
    prevSign = * 
    n2 = 4 

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // returns number starting from i
    int getNumber(string &s, int &i) {
        string numStr = "";
        while(i < s.length() && isdigit(s[i])) {
            numStr += s[i];
            i++;
        }
        i--;
        int num = stoi(numStr);
        return num;
    }

    // returns operator at i
    char getOperator(string &s, int &i) {
        char op = s[i];
        return op;
    }

public:
    int calculate(string s) {

        // add dummy '+' at the end
        s.push_back('+');

        stack<int> numbers;

        // start number is always positive
        char prevSign = '+'; 
        int n2 = 0;

        for(int i=0; i<s.length(); i++) {
        
            // skip white spaces
            if(s[i] == ' ') continue;

            // current number is a digit,
            // remember it as n2
            if(isdigit(s[i])) {
                n2 = getNumber(s, i);
            } 

            // encountered an operator
            else {
                
                // get the current operator
                char op = getOperator(s, i);
                
                // resolve the previous operator
                if(prevSign == '+') {
                    numbers.push(n2);
                } 
                else if(prevSign == '-') {
                    numbers.push(-n2);
                }
                else if(prevSign == '*') {
                    int n1 = numbers.top(); numbers.pop();
                    numbers.push(n1 * n2);
                }
                else if(prevSign == '/') {
                    int n1 = numbers.top(); numbers.pop();
                    numbers.push(n1 / n2);
                }

                // set prevSign as current sign
                prevSign = op;
            }
        }

        // add all the numbers in the stack
        int result = 0;
        while(!numbers.empty()) {
            result += numbers.top();
            numbers.pop();
        }

        return result;
        
    }
};