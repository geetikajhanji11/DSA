/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    bool canIntersect(vector<int> i1, vector<int> i2) {
        int start = max(i1[0], i2[0]);
        int end = min(i1[1], i2[1]);
        return start <= end;
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty() || secondList.empty()) return {};

        int i = 0;
        int j = 0;

        vector<vector<int>> result;

        while(i < firstList.size() && j < secondList.size()) {

            vector<int> i1 = firstList[i];
            vector<int> i2 = secondList[j];

            if(canIntersect(i1, i2)) {
                result.push_back({max(i1[0], i2[0]), min(i1[1], i2[1])});
            }

            // Remove the interval with the smallest endpoint
            if(i1[1] < i2[1]) i++;
            else j++;

        } 

        return result;
    }
};