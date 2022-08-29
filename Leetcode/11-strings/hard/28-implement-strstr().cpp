/*******************************************************************
https://www.youtube.com/watch?v=JoF0Z7nVSrA&ab_channel=NeetCode
NAIVE => O(MN) => EASY
KMP ALGO => O(M + N) => HARD
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** NAIVE APPROACH **************
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.length() > haystack.length()) return -1;
        
        for(int i=0; i<haystack.length() - needle.length() + 1; i++) {
            if(haystack[i] == needle[0]) {
                int temp_i = i;
                int j = 0;
                while(j < needle.length()) {
                    if(haystack[temp_i] != needle[j]) break;
                    temp_i++;
                    j++;
                }
                if(j == needle.length()) return i;
            }
        }

        return -1;
    }
};


// ************** KMP ALGORITHM **************
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.length() > haystack.length()) return -1;
        if(needle.length() == 0) return 0;

        // Generate LPS
        vector<int> LPS(needle.length(), 0);
        int prevLPS = 0;
        int j = 1;

        while(j < needle.length()) {
            
            if(needle[j] == needle[prevLPS]) {
                LPS[j] = prevLPS + 1;
                j++;
                prevLPS++;
            }

            else if(prevLPS == 0) {
                LPS[j] = 0;
                j++;
            }

            else {
                prevLPS = LPS[prevLPS - 1];
            }
        }

        // KMP Algorithm
        int i = 0;
        j = 0;

        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if(j == 0) {
                    i++;
                } else {
                    j = LPS[j - 1];
                }
            }

            if(j == needle.length()) return i - needle.length();
        }
        
        return -1;
    }
};