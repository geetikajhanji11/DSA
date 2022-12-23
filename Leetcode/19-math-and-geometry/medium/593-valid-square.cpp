/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // distance b/w 2 points
    long long distance(vector<int> &p1, vector<int> &p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_set<long long> s;

        // calculate distance for every pair
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                int d = distance(points[i], points[j]);

                if(d == 0) return false;
                s.insert(d);
                    
            }
        }

        // at the end, only 2 values should be left
        // side of square and diagonal
        return s.size() == 2;
    }
};