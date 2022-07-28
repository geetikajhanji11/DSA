/*******************************************************************
Given array of intervals, return min # of intervals to remove for all non-overlapping
Ex. intervals = [[1,2],[1,3],[2,3],[3,4]] -> 1, remove [1,3] for all non-overlapping

Remove interval w/ longer end point, since will always overlap more or = vs shorter one

Time: O(n log n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), 
        [](const auto& a, const auto& b) {
            return a[0] < b[0]; 
        }
    );

    int meetings_removed = 0;
    
    int prev_end = intervals[0][1];

    for(int i=1; i<n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(start >= prev_end) { // not overlapping
            prev_end = end;
        } else { // overlapping
            meetings_removed++;
            prev_end = min(prev_end, end); // remove the meeting with greater end value
        }
    }
   
    return meetings_removed;
}

int main() {

    return 0;
}