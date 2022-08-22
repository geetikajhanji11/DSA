/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string generateTarget(bool evenZero, int n) {
    string target = "";
    for(int i=0; i<n; i++) {
        if((evenZero && i % 2 == 0) || (!evenZero && i % 2 != 0)) {
            target += "0";
        } else {
            target += "1";
        }
    }
    return target;
}


int minFlips(string s) {

    int n = s.length();

    s += s;
    string target1 = generateTarget(true, s.length());
    string target2 = generateTarget(false, s.length());

    int diff1 = 0;
    int diff2 = 0;

    for(int i=0; i<n; i++) {
        if(target1[i] != s[i]) diff1++;
        if(target2[i] != s[i]) diff2++;
    }

    int left = 0;
    int right = n;
    int result = min(diff1, diff2);

    // sliding window
    int new_n = 2 * n;
    while(right < new_n) {

        // adding right
        if(s[right] != target1[right]) diff1++;
        if(s[right] != target2[right]) diff2++;

        // removing left
        if(s[left] != target1[left]) diff1--;
        if(s[left] != target2[left]) diff2--;
        left++;

        result = min(result, min(diff1, diff2));

        right++;
    }

    return result;
}
