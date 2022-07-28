/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> result;
    
    sort(intervals.begin(), intervals.end(), 
        [](const auto& a, const auto& b) {
            return a[0] < b[0]; 
        }
    );

    vector<int> prev_interval = intervals[0];
    for(int i=1; i<n; i++) {
        vector<int> curr_interval = intervals[i];
        if(curr_interval[0] >= prev_interval[0] && curr_interval[0] <= prev_interval[1]) {
            prev_interval[0] = min(prev_interval[0], curr_interval[0]);
            prev_interval[1] = max(prev_interval[1], curr_interval[1]);
        } else {
            result.push_back(prev_interval);
            prev_interval = curr_interval;
        }
    }

    result.push_back(prev_interval);
    return result;
}


int main() {

    return 0;
}