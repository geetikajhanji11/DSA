/*******************************************************************
LONGEST COMMON SUBSEQUENCE
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Top-Down Approach
int lcs_top_down(string s1, string s2, int i, int j) {

    if(i == s1.length() || j == s2.length()) return 0;

    // if current char equal
    if(s1[i] == s2[j]) {
        return 1 + lcs_top_down(s1, s2, i+1, j+1);
    }

    // if not equal
    int include = lcs_top_down(s1, s2, i, j+1);
    int exclude = lcs_top_down(s1, s2, i+1, j);

    return max(include, exclude);
}

// DP approach
int lcs_dp(string s1, string s2, int i, int j, vector<vector<int>> &dp) {

    if(i == s1.length() || j == s2.length()) return 0;

    // if state is already computed
    if(dp[i][j] != -1) return dp[i][j];

    // if current char equal
    if(s1[i] == s2[j]) {
        dp[i][j] = 1 + lcs_dp(s1, s2, i+1, j+1, dp); 
        return dp[i][j];
    }

    // if not equal
    int include = lcs_dp(s1, s2, i, j+1, dp);
    int exclude = lcs_dp(s1, s2, i+1, j, dp);

    dp[i][j] = max(include, exclude);
    return dp[i][j];
}

// bottom-up
int lcs_bottom_up(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {

            // 1-based indexing
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                int include = dp[i][j-1];
                int exclude = dp[i-1][j];
                dp[i][j] = max(include, exclude);
            }
        }
    }

    // printing the matrix
    cout<<"\nBottom-Up LCS Matrix\n";
    for(int i=0; i<=n1; i++) {
        for(int j=0; j<=n2; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // finding the string
    string s = "";
    int i = n1;
    int j = n2;
    while(i != 0 && j != 0) {
        if(dp[i][j] == dp[i][j-1]) j--;
        else if(dp[i][j] == dp[i-1][j]) i--;
        else {
            s += s1[i-1];
            i--;
            j--;
        }
    }
    reverse(s.begin(), s.end());
    cout<<"Bottom-Up String = "<<s;

    return dp[n1][n2];
}

int main() {

    string s1 = "ABCD";
    string s2 = "ABEDG";

    // top-down 
    cout<<"\nTop-Down = "<<lcs_top_down(s1, s2, 0, 0);

    // dp
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout<<"\n\nTop-Down DP = "<<lcs_dp(s1, s2, 0, 0, dp)<<endl;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // bottom-up
    int ans = lcs_bottom_up(s1, s2);
    cout<<"\nBottom-Up DP = "<<ans;

    return 0;
}