/*******************************************************************
 * COUNTING SUBSEQUENCE
 * 
 * Given two strings, find the number of times the second string
 * occurs as a subsequence in the first string.
 * 
 * Input:
 *      s1 = "ABCDCE"
 *      s2 = "ABC"
 * 
 * Ouput: 
 *      2
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

// top-down dp
int count_subsequences_top_down(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
    
    // ****** base cases ******

    // s1 and s2 both are finished OR 
    // only s2 is finished, we found subsequence
    if(i == -1 && j == -1 || j == -1) return 1;

    // s2 can't lie in s1
    if(i == -1) return 0;

    // ****** rec case ******

    // already computed
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) {
        int include = count_subsequences_top_down(i-1, j, s1, s2, dp);
        int exclude = count_subsequences_top_down(i-1, j-1, s1, s2, dp);
        return dp[i][j] = include + exclude;
    }

    return dp[i][j] = count_subsequences_top_down(i-1, j, s1, s2, dp);

}

// bottom-up dp
int count_subsequences_bottom_up(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=0; i<=n1; i++) dp[i][0] = 1;

    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"\nBottom-Up DP Matrix\n";
    for(auto v : dp) {
        for(int num : v) {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return dp[n1][n2];
}

int main() {

    string s1 = "ABCDCE";
    string s2 = "ABC";
    int n1 = s1.size();
    int n2 = s2.size();

    // top-down dp
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    int ans = count_subsequences_top_down(n1-1, n2-1, s1, s2, dp);
    // cout<<"\nTop-Down DP Matrix\n";
    // for(auto v : dp) {
    //     for(int num : v) {
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"Top-Down DP = "<<ans;

    // bottom-up dp
    ans = count_subsequences_bottom_up(s1, s2);
    cout<<"Bottom-Up DP = "<<ans;
    
    return 0;
}

*/

// ************* TOP - DOWN *************
int count_subsequuences(int i, int j, string s1, string s2, vector<vector<int>> &dp) {

    if(j == s2.length()) return 1;
    if(i == s1.length() && j != s2.length()) return 0;
    
    if(dp[i][j] != 0) return dp[i][j];

    int total = 0;
    if(s1[i] == s2[j]) {
        int op1 = count_subsequuences(i+1, j+1, s1, s2, dp);
        int op2 = count_subsequuences(i+1, j, s1, s2, dp);
        total += op1 + op2;
    } else {
        int op = count_subsequuences(i+1, j, s1, s2, dp);
        total += op;
    }
    
    return dp[i][j] = total;
}

// ************* BOTTOM - UP *************
int count_subs(string s1, string s2, bool top_down) {

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    if(top_down) {
        return count_subsequuences(0, 0, s1, s2, dp);
    }

    // bottom - up
    for(int i=0; i<=n1; i++) dp[i][0] = 1;
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"\ntable\n";
    for(int i=0; i<=n1; i++) {
        for(int j=0; j<=n2; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n1][n2];
}

int main() {

    string s1 = "ABCDCE";
    string s2 = "ABC";
    cout<<"\nTop-Down = "<<count_subs(s1, s2, true)<<endl;
    cout<<"\nBottom-Up = "<<count_subs(s1, s2, false);

    return 0;
}