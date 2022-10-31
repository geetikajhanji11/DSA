/*******************************************************************
"bbbextm"
"bbb#extm"
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i = s.length() - 1;
        int i_skips = 0;

        int j = t.length() - 1;
        int j_skips = 0;

        while(i >= 0 && j >= 0) {

            while(i >= 0 && (!isalpha(s[i]) || i_skips > 0)) {
                if(s[i] == '#') i_skips++;
                else if(isalpha(s[i])) i_skips--;
                i--;
            }

            while(j >= 0 && (!isalpha(t[j]) || j_skips > 0)) {
                if(t[j] == '#') j_skips++;
                else if(isalpha(t[j])) j_skips--;
                j--;
            }

            if(i == -1 && j == -1) return true;
            if(i == -1 || j == -1) return false;

            if(s[i] != t[j]) return false; 
            
            i--;
            j--;
            
        }
        
        if(i >= 0) {
            while(i >= 0 && (!isalpha(s[i]) || i_skips > 0)) {
                if(s[i] == '#') i_skips++;
                else if(isalpha(s[i])) i_skips--;
                i--;
            }
        }
        
        if(j >= 0) {
            while(j >= 0 && (!isalpha(t[j]) || j_skips > 0)) {
                if(t[j] == '#') j_skips++;
                else if(isalpha(t[j])) j_skips--;
                j--;
            }
        }
        
        return (i == -1 && j == -1);
    }
};