/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, unsigned long long prevNum, string &s, int ctr) {

    if(i == s.length()) {
        if(ctr == 1) return false;
        return true;
    }

    unsigned long long currNum = 0;

    for(int j=i; j<s.length(); j++) {
        currNum = (currNum * 10) + (s[j] - '0');
        if(prevNum == -1 || prevNum == currNum + 1) {
            if(dfs(j+1, currNum, s, ctr+1)) return true;
        }
        if(prevNum != -1 && currNum > prevNum) break;
    }

    return false;
}

// prevNum = -1 represents it si the first number of sequence
bool splitString(string s) {
    if(s.length() <= 1) return false;
    return dfs(0, -1, s, 0);
}


// ************* MY ORIGINAL *****************
// Logic is correct but Runtime Error for annoying edge cases
bool dfs1(int i, long long int prevNum, string &s, int ctr) {

    if(i == s.length()) {
        if(ctr == 1) return false;
        return true;
    }

    long long int currNum = 0;

    for(int j=i; j<s.length(); j++) {
        currNum = (currNum * 10) + (s[j] - '0');
        if(prevNum == currNum + 1) {
            if(dfs(j+1, currNum, s, ctr+1)) return true;
        }
        if(currNum > prevNum) break;
    }

    return false;
}

bool splitString(string s) {

    long long int currNum = 0;
    for(int i=0; i<s.length(); i++) {
        currNum = (currNum * 10) + (s[i] - '0');
        if(dfs1(i+1, currNum, s, 1)) return true;
    }
    return false;
}

int main() {

    return 0;
}