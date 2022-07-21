/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// --------------- TOP-DOWN APPROACH ---------------
bool dfs(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &dp) {

    if(k == s3.length()) {
        if(i == s1.length() && j == s2.length()) return true;
        else return false;
    }

    if(i <= s1.length() && j <= s2.length() && dp[i][j] != -1) return dp[i][j];

    // character matches with s1 string
    if(i < s1.length() && s1[i] == s3[k]) {
        if(dfs(i+1, j, k+1, s1, s2, s3, dp)) return dp[i][j] = true;
    }

    // character matches with s2 string
    if(j < s2.length() && s2[j] == s3[k]) {
        if(dfs(i, j+1, k+1, s1, s2, s3, dp)) return dp[i][j] = true;
    }

    return dp[i][j] = false;
}

bool isInterleave(string s1, string s2, string s3) {
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
    return dfs(0, 0, 0, s1, s2, s3, dp);
}

// --------------- BOTTOM-UP APPROACH ---------------
bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    if(n1 + n2 != n3) return false;

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    dp[n1][n2] = 1;

    for(int i=n1; i>=0; i--) {
        for(int j=n2; j>=0; j--) {
        
            // check down
            if(i < n1 && s1[i] == s3[i+j] && dp[i+1][j]) {
                dp[i][j] = true;
            }

            // check right
            if(j < n2 && s2[j] == s3[i+j] && dp[i][j+1]) {
                dp[i][j] = true;
            }
        }
    }

    return dp[0][0];
    
}


int main() {

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout<<isInterleave(s1, s2, s3);
    return 0;
}