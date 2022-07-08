/******************************************************************************

COUNT RECTANGLES

Given N cartesian point in a 2d plane, find the number of axis parallel
rectangles that can be formed.

Input: 
    n = 8
    arr = {
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 0},
        {2, 1},
        {2, 0},
        {3, 1},
        {3, 0}
    }
    
Output: 
    6

Explanation:
    {1, 4, 16}
    {1, 4, 16}
    {4, 16, 64}
    

*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

int numberOfRectangles(vector<pair<int, int> > all2dPoints) {
    
    int count = 0;
    unordered_map<int, unordered_set<int>> mappingXtoY;
    
    for(auto point : all2dPoints) {
        
        int x = point.first;
        int y = point.second;
        
        if(mappingXtoY.find(x) != mappingXtoY.end()) {
            mappingXtoY[x].insert(y);
        } else {
            unordered_set<int> yPoints;
            yPoints.insert(y);
            mappingXtoY[x] = yPoints;
        }
    }
    
    // display mappingXtoY
    cout<<"\nx: y points\n";
    for(auto& it : mappingXtoY) {
        cout<<it.first<<": ";
        for(int y : it.second) {
            cout<<y<<", ";
        }
        cout<<endl;
    }
    
    // after creating the mappingXtoY
    int n = all2dPoints.size();
    for(int i=0; i<n-1; i++) {
        auto point1 = all2dPoints[i];
        
        for(int j=i+1; j<n; j++) {
            auto point2 = all2dPoints[j];
            
            // coordinates of point 1
            int x1 = point1.first;
            int y1 = point1.second;
            
            // coordinates of point 2
            int x2 = point2.first;
            int y2 = point2.second;
            
            // if x1 = x2 or y1 = y2, 
            // it does not form a diagonal,
            // so continue to next
            if(x1 == x2 || y1 == y2) {
                continue;
            }
            
            // coordinates of point 3
            // if y3 does not exist in map,
            // (x3, y3) is not a given point, continue
            int x3 = x1; 
            int y3 = y2;
            if(mappingXtoY[x3].find(y3) == mappingXtoY[x3].end()) {
                continue;
            }
            
            // coordinates of point 4
            // if y4 does not exist in map,
            // (x4, y4) is not a given point, continue
            int x4 = x2;
            int y4 = y1;
            if(mappingXtoY[x4].find(y4) == mappingXtoY[x4].end()) {
                continue;
            }
            
            count++;
            
        }
    }
    
    return count / 2;
    
}

int main() {
    
    vector< pair <int,int> > all2dPoints{
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 0},
        {2, 1},
        {2, 0},
        {3, 1},
        {3, 0}
    };
        
    int result = numberOfRectangles(all2dPoints);
    cout<<"\nNumber of rectangles = "<<result;
    
    return 0;
}
