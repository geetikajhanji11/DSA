/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    // stack is in increasing order of heights
    stack<pair<int, int>> s; // index, height

    int max_area = 0;
    for(int i=0; i<n; i++) {
        if(!s.empty() && s.top().second > heights[i]) {
            pair<int, int> top;
            while(!s.empty() && s.top().second > heights[i]) {
                top = s.top();
                s.pop();
                int curr_area = top.second * (i - top.first);
                max_area = max(max_area, curr_area);
            }
            s.push({top.first, heights[i]});
        } else {
            s.push({i, heights[i]});
        }
    }


    while(!s.empty()) {
        auto top = s.top();
        s.pop();
        int curr_area = top.second * (n - top.first);
        max_area = max(max_area, curr_area);
    }

    return max_area;
}

int main() {

    return 0;
}