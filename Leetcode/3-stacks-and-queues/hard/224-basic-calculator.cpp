/*******************************************************************
class Solution {
public:
    int calculate(string s) {
        stack<int> op({1});
        int total = 0, num = 0;
        int isPositive = 1;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                total += num * isPositive * op.top();
                num = 0;
                if (c == '+') isPositive = 1;
                if (c == '-') isPositive = -1;
                if (c == ')') op.pop();
                if (c == '(') {
                    op.push(op.top() * isPositive);
                    isPositive = 1;
                }
            }
        }
        total += num * isPositive * op.top();
        return total;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        stack<int> numStack;
        int prevSign = 1; // started with '+'
        int num = 0;
        int result = 0;

        for(int i=0; i<s.length(); i++) {

            if(s[i] == ' ') continue;

            // found a number
            if(isdigit(s[i])) {
                string str = "";
                while(isdigit(s[i])) {
                    str += s[i];
                    i++;
                }
                i--;
                num = stoi(str);
            } 

            // result and prevSign are pushed onto stack
            else if(s[i] == '(') {
                numStack.push(result);
                numStack.push(prevSign);

                // reset for computation inside ()
                prevSign = 1; // make it positive
                result = 0;
            }
            
            // first sign is popped
            // then prevResult is popped
            else if(s[i] == ')') {
                result += (prevSign * num);

                int stackSign = numStack.top(); numStack.pop();
                int stackResult = numStack.top(); numStack.pop();
                result = stackResult + (stackSign * result);

                // reset
                num = 0;
            } 

            // either "+" or "-"
            else {
                result += (prevSign * num);
                num = 0;
                
                if(s[i] == '+') prevSign = 1;
                else prevSign = -1;
            }
        }


        if(num != 0) {
            result += (prevSign * num);
        }

        return result;
    }
};