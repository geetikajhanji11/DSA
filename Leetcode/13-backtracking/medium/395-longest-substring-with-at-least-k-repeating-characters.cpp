/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ****************** YOUTUBE SOLUTION ******************
class Solution {

    int lss(int i, int j, int &k, string &s) {
        if(i > j) return 0;
        if(k == 0 || k == 1) return j - i + 1;
        if(k > j - i + 1) return 0; 

        // count frequency of each character
        vector<int> freq(26, 0);
        for(int idx=i; idx<=j; idx++) freq[s[idx]-'a']++;

        // traverse string until it is invalid
        int idx = i;
        while(idx <= j && freq[s[idx]-'a'] >= k) idx++;

        // whole string is valid
        if(idx == j+1) return j - i + 1;

        // string invalid at idx
        int lss1 = lss(i, idx-1, k, s);
        while(idx <= j && freq[s[idx]-'a'] < k) idx++;
        int lss2 = lss(idx, j, k, s);

        return max(lss1, lss2);
    }

public:
    int longestSubstring(string s, int k) {
        return lss(0, s.length()-1, k, s);
    }
};

// ****************** MY SOLUTION ****************** 

class Solution {

    // recursive function
    int lss(string s, int i, int j, int k) {
        if(i > j) return 0;
        if(i == j) {
            if(k == 1) return 1;
            return 0;
        }

        vector<int> freq(26, 0);
        vector<bool> isValid(26, false);

        for(int x=i; x<=j; x++) {
            int letter = s[x] - 'a';
            freq[letter]++;
            if(!isValid[letter] && freq[letter] >= k) {
                isValid[letter] = true;
            }
        }

        int start = i;
        int end = i;
        int maxLength = 0;
        bool hasInvalid = false;
        vector<int> count(26, 0);
        
        while(end <= j) {

            // found a splitting point
            // i.e., invalid character
            if(!isValid[s[end] - 'a']) {
                hasInvalid = true;
                
                // LHS = s1
                maxLength = max(maxLength, lss(s, start, end - 1, k));
                
                // skip all in between invalid characters
                while(end <= j && !isValid[s[end] - 'a']) end++;
                
                // RHS = s2
                maxLength = max(maxLength, lss(s, end, j, k));
                
                break;
            } 
            
            // did not finding a splitting character
            else {
                end++;
            }
            
        }

        // whole string is valid string
        if(!hasInvalid) return j - i + 1;

        // string was divided into s1 , s2
        return maxLength;
    }

public:
    int longestSubstring(string s, int k) {
        return lss(s, 0, s.length()-1, k);
    }
};