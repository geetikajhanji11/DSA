/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || 
                ch == 'i' || ch == 'o' || 
                ch == 'u' || ch == 'A' ||
                ch == 'E' || ch == 'I' ||
                ch == 'O' || ch == 'U');
    }

public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length();

        while(i < j) {
            while(i < j && !isVowel(s[i])) i++;
            while(i < j && !isVowel(s[j])) j--;

            if(i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};