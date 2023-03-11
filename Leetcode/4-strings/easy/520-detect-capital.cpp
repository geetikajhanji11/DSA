/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() <= 1) return true;

        bool isUppercase = isupper(word[1]);
        for(int i=2; i<word.length(); i++) {
            bool curr = isupper(word[i]);
            if(isUppercase != curr) return false; 
        }

        if(isUppercase && islower(word[0])) return false;

        return true;
    }
};