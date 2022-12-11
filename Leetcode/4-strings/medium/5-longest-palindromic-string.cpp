/*******************************************************************
NEXT => 647-palindromic-substrings
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {

    int n = s.length();

    string result = "";
    int result_length = 0;

    for(int i=0; i<n; i++) {

        // odd length
        int left = i;
        int right = i;
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int length = right - left - 1;
        if(length > result_length) {
            result_length = length;
            result = s.substr(left+1, length);
        }

        // even length
        left = i;
        right = i+1;
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        length = right - left - 1;
        if(length > result_length) {
            result_length = length;
            result = s.substr(left+1, length);
        }
    }

    return result;
}

int main() {

    return 0;
}