/*******************************************************************
Consider f(i, j) is the minimum cost of printing the substring
si, ......, sj (inclusive). We always have to print si, 
so we can consider printing it first, last, or any time in between, 
but let's consider printing this character first because then we 
can always take advantage of it - at worst, we can reprint the 
same character if necessary later on.

Now a default case is to stop printing si after one character, 
and moving on. This transition is f(i, j) = f(i+1, j) + 1, 
as 1 is the cost of printing si.

We also want to consider stopping at index mm, where si = sm.
The statement is that we printed si between [si, sm]
and we want to consider the subproblems of f(i, m-1) 
where we continue to consider the next right-most boundary 
we're still using si, and f(m+1, j), the other leftover portion 
of the subproblem where we no longer need to use si.

Putting it all together, our base case is f(i,i) = 1, the cost of printing one character.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {

    int minTurns(int left, int right, string &s,  vector<vector<int>> &dp) {
        if(left > right) return 0;
        if(left == right) return 1;

        if(dp[left][right] != -1) return dp[left][right];

        int ans = minTurns(left+1, right, s, dp) + 1;
        for(int i=left+1; i<=right; i++) {
            if(s[i] == s[left]) {
                int turns = minTurns(left, i-1, s, dp) + minTurns(i+1, right, s, dp);
                ans = min(ans, turns);
            }
        }

        return dp[left][right] = ans;
    }

public:
    int strangePrinter(string s) {
        
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return minTurns(0, s.length()-1, s, dp);
    
    }
};