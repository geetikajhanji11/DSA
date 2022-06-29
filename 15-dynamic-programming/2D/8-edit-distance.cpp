/*******************************************************************
 * EDIT DISTANCE
 * 
 * Given two strings str1 and str2 and below operations that can
 * be performed on str1. Find the minimum number of edits 
 * (operations: insert, remove, replace) required to convert 
 * str1 into str2. All operations are of equal cost.
 * 
 * Input:
 *      str1 = "geek"
 *      str2 = "gesek"
 * 
 *      str1 = "cat"
 *      str2 = "cut"
 * 
 *      str1 = "sunday"
 *      str2 = "saturday"
 * 
 * Output:
 *      1
 *      1
 *      3 
 *      Explanation-3: 
 *          Last 3 letters and first letter are same. We need to
 *          convert "un" to "atur". This can be done using below 
 *          operations:
 *              => replace "n" with "r"
 *              => insert "t"
 *              => insert "a"
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimum_cost(int i, int j, string s1, string s2, vector<vector<int>> &dp) {

    // if s1 is finished, rest of the characters 
    // of s2 HAVE to be inserted, so cost will be
    // equal to remaining characters left of s2
    // and vice versa for s1.
    if(i == s1.length()) return (s2.length() - j);
    if(j == s2.length()) return (s1.length() - i);

    if(dp[i][j] != -1) return dp[i][j];
    

    if(s1[i] == s2[j]) {
        return dp[i][j] = minimum_cost(i+1, j+1, s1, s2, dp);
    }

    int insert_cost = minimum_cost(i, j+1, s1, s2, dp);
    int remove_cost = minimum_cost(i+1, j, s1, s2, dp);
    int replace_cost = minimum_cost(i+1, j+1, s1, s2, dp);

    int min_cost = min(insert_cost, min(remove_cost, replace_cost));

    return dp[i][j] = 1 + min_cost;
}

int editDistance(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    return minimum_cost(0, 0, str1, str2, dp);
}

int main() {

    string s1 = "sunday";
    string s2 = "saturday";

    cout<<editDistance(s1, s2);
    return 0;
}