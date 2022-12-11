/*******************************************************************
Given array of non-overlapping intervals & a new interval, insert & 
merge if necessary
Ex. intervals = [[1,3],[6,9]], newInterval = [2,5] -> [[1,5],[6,9]]

To merge: while intervals are still overlapping the new one, take the larger bounds

Time: O(n)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int i = 0;
    int n = intervals.size();
    
    vector<vector<int>> result;
    
    // inserted everything before the overlapping part
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    
    // now we have to insert interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}

int main() {

    vector<vector<int>> intervals = {
        {1,2},
        {3,5},
        {6,7},
        {8,10},
        {12,16}
    };

    vector<int> newInterval = {9, 11};

    auto res = insert(intervals, newInterval);
    cout<<"\n\nans\n";
    for(auto v : res) {
        for(int n : v) cout<<n<<", ";
        cout<<endl;
    }
    return 0;
}