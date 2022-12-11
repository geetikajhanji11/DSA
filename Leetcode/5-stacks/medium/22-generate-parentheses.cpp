/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generate(string curr, int open, int close, vector<string> &result, int n) {
    if(curr.length() == 2*n) {
        result.push_back(curr);
        return;
    }

    if(open < n) {
        generate(curr + "(", open+1, close, result, n);
    }

    if(close < open) {
        generate(curr + ")", open, close+1, result, n);
    }

}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate("", 0, 0, result, n);
    return result;
}

int main() {

    return 0;
}