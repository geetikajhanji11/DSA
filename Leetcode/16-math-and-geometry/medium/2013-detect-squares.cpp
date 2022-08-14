/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DetectSquares {
public:

    map<pair<int, int>, int> pointCount;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pointCount[{x, y}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

       int result = 0;

       for(auto diagPointCount : pointCount) {
            int dx = diagPointCount.first.first;
            int dy = diagPointCount.first.second;
            int dcount = diagPointCount.second;

            if((abs(y - dy) != abs(x - dx)) || x == dx || y == dy) continue;

            if(pointCount.find({x, dy}) == pointCount.end()) continue;
            if(pointCount.find({dx, y}) == pointCount.end()) continue;
            
            result += 1 * dcount * pointCount[{x, dy}] * pointCount[{dx, y}];
       }
       return result;
    }
};


int main() {

    return 0;
}