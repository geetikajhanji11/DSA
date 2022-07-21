/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string LCS(string text1, string text2, vector<vector<int>> &dp) {
    string str = "";

    int i = text1.length();
    int j = text2.length();

    while(i > 0 && j > 0) {
        if(text1[i-1] == text2[j-1]) {
            str += text1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] <= dp[i][j-1]) j--;
        else i--;
    }

    reverse(str.begin(), str.end());
    return str;
}

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<"string = "<<LCS(text1, text2, dp)<<endl;

    return dp[n1][n2];
}

int main() {

    int len = longestCommonSubsequence("ace", "abcde");
    cout<<"length = "<<len;
    return 0;
}