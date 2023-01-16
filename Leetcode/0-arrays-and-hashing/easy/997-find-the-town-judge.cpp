/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> countTrusts(n+1, 0);

        for(auto t : trust) {
            countTrusts[t[0]]--;
            countTrusts[t[1]]++;
        }

        for(int i=1; i<=n; i++) {
            if(countTrusts[i] == n - 1) return i;
        }

        return -1;

    }
};