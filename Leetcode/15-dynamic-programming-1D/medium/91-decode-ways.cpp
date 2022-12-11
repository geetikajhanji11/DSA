#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ------------- TOP-DOWN APPROACH -------------
int get_val(string str_num) {
    int num = stoi(str_num);
    return num;
}

int ways(int i, string s, vector<int> &dp) {

    if(i == s.length()) return 1;
    if(s[i] == '0') return 0; 
    if(dp[i] != -1) return dp[i];

    int ways1 = ways(i+1, s, dp);
    int ways2 = 0;
    if(i+1 < s.length() && stoi(s.substr(i, 2)) <= 26) {
        ways2 = ways(i+2, s, dp); 
    } 

    int total_ways = ways1 + ways2;
    dp[i] = total_ways;

    return dp[i];
}

int numDecodings(string s) {
    vector<int> dp(s.length(), -1);
    return ways(0, s, dp);
}

// ------------- BOTTOM-UP APPROACH -------------
int numDecodings(string s) {
    int n = s.length();

    vector<int> dp(n+1, -1);
    
    for(int i=n; i>=0; i--) {

        if(i == n) {
            dp[i] = 1;
            continue;
        }

        if(s[i] == '0') {
            dp[i] = 0;
            continue;
        }

        int ways1 = dp[i+1];
        int ways2 = 0;
        if(i+1 < n && stoi(s.substr(i, 2)) <= 26) {
            ways2 = dp[i+2];
        }

        dp[i] = ways1 + ways2;
    }

    return dp[0];
}

int main() {

    string s = "226";
    cout<<numDecodings(s);
    return 0;
}