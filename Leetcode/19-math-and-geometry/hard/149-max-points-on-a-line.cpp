/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********************* O(N^2) *********************
class Solution {

public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2) return points.size();

        int result = 0;

        // fix point 1
        for(auto point1 : points) {
            double x1 = point1[0];
            double y1 = point1[1];

            unordered_map<double, int> count;

            // for all possible point 2
            for(auto point2 : points) {
                double x2 = point2[0];
                double y2 = point2[1];

                // same point
                if(point1 == point2) continue;

                // calculate slope
                double slope = 0.0;
                if(x2 - x1 == 0) {
                    slope = INT_MAX;
                } else {
                    slope = (y2 - y1) / (x2 - x1); 
                }
                
                count[slope]++;
                result = max(result, count[slope]);
               
            }
        }

        // including the fixed point1
        return result + 1;
    }
};

// ********************* O(N^3) *********************
class Solution {

    bool isSamePoint(vector<int> &p1, vector<int> &p2) {
        return (p1[0] == p2[0]) && (p1[1] == p2[1]);
    }

    int pointsOnLine(vector<int> &point1, vector<int> &point2, vector<vector<int>>& points) {
        
        int totalPoints = 2;

        int x1 = point1[0];
        int y1 = point1[1];

        int x2 = point2[0];
        int y2 = point2[1];

        for(auto point : points) {
            if(isSamePoint(point1, point)) continue;
            if(isSamePoint(point2, point)) continue;
            
            int x = point[0];
            int y = point[1];

            long long LHS = (y - y1) * (x2 - x1);
            long long RHS = (y2 - y1) * (x - x1);

            if(LHS == RHS) totalPoints++; 
        }

        return totalPoints;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        if(points.size() == 1) return 1;

        vector<pair<int, int>> linePoints;

        int result = 0;
        for(int i=0; i<points.size()-1; i++) {
            for(int j=i+1; j<points.size(); j++) {
                auto point1 = points[i];
                auto point2 = points[j];
                int totalPoints = pointsOnLine(point1, point2, points);
                result = max(result, totalPoints);
            }
        }

        return result;
    }
};