/**************************************************************

https://www.youtube.com/watch?v=s9fokUqJ76A&ab_channel=NeetCode

GENERATE PARENTHESES

Given n pairs of parentheses, write a function to generate 
all combinations of well-formed parentheses.

Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
    Input: n = 1
    Output: ["()"]

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;


void recur(vector<string> &result, string curr, int n, int close, int open) {

    // base case
    if(open == n && close == n) {
        result.push_back(curr);
        return;
    }

    // rec cases

    // 1.   open brackets are not enough in curr string
    //      so add OPEN
    if(open < n) {
        curr.push_back('(');
        recur(result, curr, n, close, open+1);
        curr.pop_back();
    }

    // 2.   open brackets > close brackets, so
    //      we can include close bracket, add CLOSE
    if(close < open) {
        curr.push_back(')');
        recur(result, curr, n, close+1, open);
        curr.pop_back();
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    recur(result, "", n, 0, 0);
    return result;
}


// main function 
int main() {
    vector<string> res = generateParentheses(3);

    for(string str : res) {
        cout<<str<<endl;
    }

    
}