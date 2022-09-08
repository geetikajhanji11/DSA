/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string getBaseString(int decimal, int base) {
        if(decimal == 0) return "0";
        string result = "";
        while(decimal != 0) {
            result += to_string(decimal % base);
            decimal /= base;
        }
        return result;
    }

public:
    bool isStrictlyPalindromic(int n) {
        for(int base=2; base<=n-2; base++) {
            string baseString = getBaseString(n, base);
            if(!isPalindrome(baseString)) return false;
        }
        return true;
    }
};