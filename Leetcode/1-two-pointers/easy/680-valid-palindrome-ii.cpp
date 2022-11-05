/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.length() - 1;

        bool used = false;

        while(i < j) {

            if(s[i] == s[j]) {
                i++;
                j--;
            } 
            
            else {
                // delete s[i]
                bool isPal1 = isPalindrome(i+1, j, s);

                // delete s[j]
                bool isPal2 = isPalindrome(i, j-1, s);

                return isPal1 || isPal2;
            }
        }

        return true;
    }
};