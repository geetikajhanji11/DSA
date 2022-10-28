/*******************************************************************
[[10,16],[2,8],[1,6],[7,12]]
Merge intervals;


[1,6],[2,8],[7,12],[10,16],
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    static bool compare(vector<int> &point1, vector<int> &point2) {
        return point1[0] < point2[0];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
    
        vector<int> prevPoint = points[0];
        int arrows = 1;

        for(int i=1; i<points.size(); i++) {
            vector<int> currPoint = points[i];

            if(currPoint[0] >= prevPoint[0] && currPoint[0] <= prevPoint[1]) {
                prevPoint[1] = min(prevPoint[1], currPoint[1]);
            } else {
                arrows++;
                prevPoint = currPoint;
            }
        }

        return arrows;
    }
};