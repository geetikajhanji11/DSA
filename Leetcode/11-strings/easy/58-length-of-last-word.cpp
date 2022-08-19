/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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