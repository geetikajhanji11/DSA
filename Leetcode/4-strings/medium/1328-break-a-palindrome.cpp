/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n == 1) return ""; 
        for(int i=0; i<n/2; i++) {
            if(palindrome[i] == 'a') continue;
            else {
                palindrome[i] = 'a';
                return palindrome;
            }
        }        
        palindrome[n-1] = 'b';
        return palindrome;
    }
*/

string breakPalindrome(string palindrome) {
    int n = palindrome.length();
    if(n == 1) return ""; 
    for(int i=0; i<n; i++) {
        if(palindrome[i] == 'a') continue;
        if(i != n/2) {
            palindrome[i] = 'a';
            return palindrome;
        }
    }        
    palindrome[n-1] = 'b';
    return palindrome;
}

int main() {

    return 0;
}