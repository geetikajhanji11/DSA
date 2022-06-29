/*******************************************************************
 * PALINDROMIC PARTITIONING
 * 
 * Given a string s, your task is to partition s such that every
 * substring of the partition is a palindrome. Return the minimum
 * number of cuts for a palindrome partitioning of s.
 * 
 * Examples:
 * 
 *      str = "geek" => g|ee|k => 2
 *      str = "aaaa" => aaaa => 0
 *      str = "abcde" => a|b|c|d|e => 4
 *      str = "abbac" => abba|c => 1 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minimum_cuts(int i, int j, string s, vector<vector<int>> &dp) {

    if(i >= j || is_palindrome(s, i, j)) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int answer = INT_MAX;
    for(int k=i; k<j; k++) {
        
        int left_cuts = minimum_cuts(i, k, s, dp);
        int right_cuts = minimum_cuts(k+1, j, s, dp);

        int total_cuts = 1 + left_cuts + right_cuts;
        answer = min(answer, total_cuts);
    }

    return dp[i][j] = answer;
}


int partitioning(string str) {
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return minimum_cuts(0, n-1, str, dp);
}

int main() {

    string s = "geek";
    cout<<partitioning(s);
    return 0;
}