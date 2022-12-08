/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        int idx1 = -1;
        int idx2 = -1;

        int result = INT_MAX;

        for(int i=0; i<words.size(); i++) {
            if(words[i] == word1) {
                idx1 = i;
            } else if(words[i] == word2) {
                idx2 = i;
            }

            if(idx1 != -1 && idx2 != -1) {
                result = min(result, abs(idx1 - idx2));
            }
        }

        return result;
    }
};