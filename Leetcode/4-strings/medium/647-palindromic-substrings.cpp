/*******************************************************************
Similar to 5-longest-palindromic-string
*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    int ctr = 0;

    for(int i=0; i<n; i++) {
        
        // odd length
        int left = i;
        int right = i;
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
            ctr++;
        }

        // even length
        left = i;
        right = i+1;
        while(left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
            ctr++;
        }
    }

    return ctr;
}

int main() {

    return 0;
}