/*******************************************************************
Check Bitmask DP Solution, if you have time
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ************ PASSING s1 AND s2 BY REF IMPROVED ************
class Solution {
public:

    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    void dfs(int i, string &s1, string &s2, string &s, int &result) {

        if(i == s.length()) {
            if(isPalindrome(s1) && isPalindrome(s2)) {
                int len1 = s1.length();
                int len2 = s2.length();
                result = max(result, len1 * len2);
            }
            return;
        }

        s1.push_back(s[i]);
        dfs(i+1, s1, s2, s, result);
        s1.pop_back();

        s2.push_back(s[i]);
        dfs(i+1, s1, s2, s, result);
        s2.pop_back();
        
        dfs(i+1, s1, s2, s, result);
    }
    
    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";
        int result = 0;
        dfs(0, s1, s2, s, result);
        return result;
    }
};

// ************ LOGIC CORRECT (BUT TOOK TOO LONG) ************
class Solution {
public:

    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(int i, string s1, string s2, string &s, int &result) {

        if(i == s.length()) {
            if(isPalindrome(s1) && isPalindrome(s2)) {
                int len1 = s1.length();
                int len2 = s2.length();
                result = max(result, len1 * len2);
            }
            return;
        }

        dfs(i+1, s1 + s[i], s2, s, result);
        dfs(i+1, s1, s2 + s[i], s, result);
        dfs(i+1, s1, s2, s, result);
    }

    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";
        int result = 0;
        dfs(0, s1, s2, s, result);
        return result;
    }
};