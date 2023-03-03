/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int> sortedRanks = score;
        sort(sortedRanks.begin(), sortedRanks.end());

        unordered_map<int, string> m;
        if(n >= 1) m[sortedRanks[n-1]] = "Gold Medal";
        if(n >= 2) m[sortedRanks[n-2]] = "Silver Medal";
        if(n >= 3) m[sortedRanks[n-3]] = "Bronze Medal";

        int pos = 4;
        for(int i=n-4; i>=0; i--) {
            m[sortedRanks[i]] = to_string(pos);
            pos++;
        }

        vector<string> result(n);
        for(int i=0; i<n; i++) {
            result[i] = m[score[i]];
        }

        return result;
    }
};