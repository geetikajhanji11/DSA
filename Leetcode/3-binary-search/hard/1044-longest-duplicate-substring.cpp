/*******************************************************************
https://www.youtube.com/watch?v=BQ9E-2umSWc&ab_channel=TECHDOSE
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    long prime = 1e15 + 7;
    vector<long> roll;

    string rabinKarp(string &s, int window_length) {
        if(window_length == 0) return "";

        // calculate hash for the first window
        unordered_map<long, int> hash;
        long curr = 0;
        for(int i=0; i<window_length; i++) {
            curr = (curr * 26 + (s[i] - 'a')) % prime;
        }
        hash[curr] = 0;

        // find hash of other windows
        for(int i=window_length; i<s.length(); i++) {

            int left = s[i - window_length] - 'a'; // MSB
            int right = s[i] - 'a'; // LSB

            // remove the left character MSB (26 ^ [window_length - 1])
            // [extra (+ prime) is there to avoid collisions]
            curr = ((curr - roll[window_length - 1] * left) % prime + prime) % prime;
            
            // add the right character LSB (26 ^ 0)
            curr = (curr * 26 + right) % prime;

            // check if hash exists
            if(hash.find(curr) == hash.end()) {
                hash[curr] = i - window_length + 1;
            } else {
                return s.substr(hash[curr], window_length);
            }
        }

        return "";
    }

public:
    string longestDupSubstring(string s) {
        int n = s.length();

        // roll[0] = 26^0
        // roll[1] = 26^1
        // roll[2] = 26^2 ...  and so on
        // for easy lookup for 26^k
        roll = vector<long>(n, 0);
        roll[0] = 1;
        for(int i=1; i<n; i++) {
            roll[i] = (roll[i-1] * 26) % prime;
        }

        // binary search
        int low = 1;
        int high = n - 1;
        string result;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            string duplicate = rabinKarp(s, mid);

            if(duplicate.size() > result.size()) {
                result = duplicate;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};