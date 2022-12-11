/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(vector<int> &i1, vector<int> &i2) {
        if(i1[0] == i2[0]) {
            return i1[1] > i2[1];
        } 
        return i1[0] < i2[0];
    } 
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // sort
        sort(intervals.begin(), intervals.end(), compare);

        vector<int> prevInterval = intervals[0];
        int coveredIntervals = 0;

        for(int i=1; i<n; i++) {
            vector<int> currInterval = intervals[i];
            if(prevInterval[0] <= currInterval[0] && currInterval[1] <= prevInterval[1]) {
                coveredIntervals++;
            } else {
                prevInterval = currInterval;
            }
        }

        return n - coveredIntervals;      
    }
};