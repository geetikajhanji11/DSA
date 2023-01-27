/*******************************************************************
DID NOT UNDERSTAND
https://leetcode.com/problems/valid-permutations-for-di-sequence/solutions/168278/c-java-python-dp-solution-o-n-2/

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** DISCUSS SOL ***********
class Solution {
    int MOD = 1e9 + 7;
public:
    int numPermsDISequence(string S) {
        int n = S.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int j = 0; j <= n; j++) dp[0][j] = 1;

        for (int i = 0; i < n; i++)

            if (S[i] == 'I') {
                int curr = 0;
                for (int j=0; j<n-i; j++) {
                    dp[i + 1][j] = curr = (curr + dp[i][j]) % MOD;
                }    
            }
                
            else {
                int curr = 0;
                for (int j=n-i-1; j>=0; j--) {
                    dp[i + 1][j] = curr = (curr + dp[i][j + 1]) % MOD;
                }
            }
                
        return dp[n][0];
    }
};

// *********** LOGIC CORRECT BUT TLE ***********
class Solution {

    int sequences(int i, int prevNum, vector<bool> visited, string &s, int &n) {

        if(i == s.length()) return 1;

        int ans = 0;
        for(int num=0; num<=n; num++) {

            if(s[i] == 'D' && !visited[num] && prevNum > num) {
                visited[num] = true;
                ans += sequences(i+1, num, visited, s, n);
                visited[num] = false;
            }

            if(s[i] == 'I' && !visited[num] && prevNum < num) {
                visited[num] = true;
                ans += sequences(i+1, num, visited, s, n);
                visited[num] = false;
            }
        }

        return ans;
    }

public:
    int numPermsDISequence(string s) {
        
        int n = s.length();

        vector<bool> visited(n+1, false);

        int ans = 0;
        for(int num=0; num<=n; num++) {
            visited[num] = true;
            ans += sequences(0, num, visited, s, n);
            visited[num] = false;
        }

        return ans;
    }
};