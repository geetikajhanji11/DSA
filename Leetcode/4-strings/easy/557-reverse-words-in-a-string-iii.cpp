/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        int i = 0;
        while(i < s.length()) {
            if(s[i] == ' ') continue;
            int j = i;
            while(j < s.length() && s[j] != ' ') j++;
            j--;

            int left = i;
            int right = j;
            while(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            i = j + 2;
        }

        return s;
    }
};