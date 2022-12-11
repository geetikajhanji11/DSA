/*******************************************************************
"the sky is blue"

reverse whole string
"eulb si yks eht"

reverse individual words
"blue is sky the"
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void reverseIndividualWord(string &str, int &i) {
        int left = i;
        int right = i;
        while(right < str.length() && str[right] != ' ') {
            right++;
        }

        int j = right;
        right--;

        while(left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }
        i = j;
    }

public:
    string reverseWords(string &str) {
        reverse(str.begin(), str.end());

        int i = 0;
        while(i < str.length()) {
            if(str[i] == ' ') {
                i++;
                continue;
            }
            reverseIndividualWord(str, i);
        }

        return str;
    }
};