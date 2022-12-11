/*******************************************************************
["01","101","111","10","0001","111001","1","0"]
7
5
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ***************** TOP - DOWN APPROACH *****************
class Solution {

    int max1s0s(int i, vector<pair<int, int>> &count, int m, int n, vector<vector<vector<int>>> &dp) {
        if(i == count.size()) return 0;
        if(m < 0 || n < 0) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int op1 = max1s0s(i+1, count, m, n, dp);
        int op2 = 0;
        
        if(count[i].first <= m && count[i].second <= n) {
            op2 = 1 + max1s0s(i+1, count, m - count[i].first, n - count[i].second, dp);
        }

        return dp[i][m][n] = max(op1, op2);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int, int>> count;
        for(string str : strs) {
            int ones = 0;
            int zeroes = 0;
            for(char ch : str) {
                if(ch == '1') ones++;
                else zeroes ++;
            }
            count.push_back({zeroes, ones});
        }

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return max1s0s(0, count, m, n, dp);
    }
};

// ***************** BOTTOM - UP APPROACH *****************
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int, int>> count;
        for(string str : strs) {
            int ones = 0;
            int zeroes = 0;
            for(char ch : str) {
                if(ch == '1') ones++;
                else zeroes ++;
            }
            count.push_back({zeroes, ones});
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0; i<strs.size(); i++) {

            // for every zero and one combination
            for(int zeroes=m; zeroes>=count[i].first; zeroes--) {
                for(int ones=n; ones>=count[i].second; ones--) {
                    int op1 = 1 + dp[zeroes-count[i].first][ones-count[i].second];
                    int op2 = dp[zeroes][ones];

                    dp[zeroes][ones] = max(op1, op2);
                }
            }
        }

        return dp[m][n];

    }
};