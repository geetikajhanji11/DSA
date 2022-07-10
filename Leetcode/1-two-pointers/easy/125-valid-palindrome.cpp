/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool isPalindrome(string s) {
    int n = s.length();
    int left = 0;
    int right = n - 1;

    while(left < right) {

        while(left < n && !isalnum(s[left])) left++;
        while(right >= 0 && !isalnum(s[right])) right--;
        
        if(left >= n || right < 0) return true;
        
        char l = tolower(s[left]);
        char r = tolower(s[right]);

        if(l == r) {
            left++;
            right--;
        } else {
            return false;
        }
    }

    return true; 
}

int main() {

    return 0;
}