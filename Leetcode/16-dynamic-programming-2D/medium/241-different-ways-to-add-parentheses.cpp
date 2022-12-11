/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // returns true if current char is operator
    bool isOperator(char ch) {
        return ch == '+' || ch == '*' || ch == '-';
    }

    // recursive + memoiztion dp
    vector<int> compute(int i, int j, string &expression, map<pair<int, int>, vector<int>> &dp) {

        // empty string
        if(i > j) return {};

        // check in dp
        if(dp.find({i, j}) != dp.end()) return dp[{i, j}];

        vector<int> result;

        // go through the entire string from [i, j]
        for(int pos=i; pos<=j; pos++) {
            if(isOperator(expression[pos])) {

                // compute left and right intermediate results
                vector<int> leftResult = compute(i, pos-1, expression, dp);
                vector<int> rightResult = compute(pos+1, j, expression, dp);

                // for every left and right in intermediate results
                // evaluate the expression
                for(int left : leftResult) {
                    for(int right : rightResult) {
                        if(expression[pos] == '+') result.push_back(left + right);   
                        else if(expression[pos] == '-') result.push_back(left - right);
                        else if(expression[pos] == '*') result.push_back(left * right);
                    }
                }
            }
        }
        
        // if result is empty and i <= j
        // this means result must contain single number
        if(result.empty()) {
            string numberString = expression.substr(i, j - i + 1);
            result.push_back(stoi(numberString));
        }

        // return result
        return dp[{i, j}] = result;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        map<pair<int, int>, vector<int>> dp;
        return compute(0, expression.length()-1, expression, dp);
    }
};