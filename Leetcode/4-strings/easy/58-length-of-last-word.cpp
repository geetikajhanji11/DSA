/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** NEETCODE SOLUTION ***************
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;

        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' ') i--;

        while(i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }        
        return length;
    }
};

// *************** MY SOLUTION ***************
int lengthOfLastWord(string s) {
    int length = 0;
    bool done = false;

    for(int i=s.length()-1; i>=0; i--) {
        if(s[i] == ' ') continue;
        for(int j=i; j>=0; j--) {
            if(s[j] == ' ') {
                done = true;
                break;
            }
            length++;
            done = true;
        }
        if(done) break;
    }        
    return length;
}

int main() {

    return 0;
}