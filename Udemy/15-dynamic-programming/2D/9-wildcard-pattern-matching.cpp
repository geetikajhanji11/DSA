/*******************************************************************
 * WILDCARD PATTERN MATCHING
 * 
 * Given an input string s and a pattern p, implement wildcard
 * pattern matching algorithm that finds if wildcard pattern is
 * matched with input string.
 * 
 * The wildcard pattern can include characters '?' and '*':
 *      ?   Matches any single character
 *      *   Matches any sequence of characters
 *          (including empty spaces)
 * 
 * The matching should cover the entire input string (not partial)
 * 
 * Examples:
 *      s = "baaabab"
 *      p1 = "**ba**ab" => true
 *      p2 = "baaa?ab" => true
 *      p3 = "ba*a?" => true
 *      p4 = "a*ab" => false 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool does_match(int i, int j, string s, string p, vector<vector<int>> &dp) {

    // base cases
    if(i == s.length() && j == p.length()) return true;
    if(j == p.length()) return false;
    if(i == s.length()) {
        while(j < p.length()) {
            if(p[j] != '*') return false;
            j++;
        }
        return true;
    }

    // already computed
    if(dp[i][j] != -1) return dp[i][j];

    // case-2:  either move the s string
    //          or the p string by 1 step
    if(p[j] == '*') {
        return dp[i][j] = does_match(i, j+1, s, p, dp) || does_match(i+1, j, s, p, dp);
    }

    // case-3:  move both the string s and p
    //          by 1 step
    else if(p[j] == '?') {
        return does_match(i+1, j+1, s, p, dp);
    } 

    // case-1:  found a match
    else if(s[i] == p[j]) return dp[i][j] = does_match(i+1, j+1, s, p, dp);

    return dp[i][j] = false;
    
}

bool patternMatching(string s, string p){

    int n1 = s.length();
    int n2 = p.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

    return does_match(0, 0, s, p, dp);
}

int main() {

    string s = "baaabab";
    string p = "**ba**ab";
    
    if(patternMatching(s, p)){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}