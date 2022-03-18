/******************************************************************************

COUNT TRIANGLES

Given N cartesian point in a 2d plane, find the number of right triangles 
such that the base or the perpendicular is parallel to x axis or y axis.

Input: 
    n = 8
    arr = {
        {1, 2},
        {2, 0},
        {2, 2},
        {2, 3},
        {4, 2},
    }
    
Output: 
    4
    
*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

int numberOfTriangles(vector<pair<int, int> > all2dPoints) {
    
    int count = 0;
    unordered_map<int, int> x_map; // x => frequency of x
    unordered_map<int, int> y_map; // y => frequency of y
    
    for(auto point : all2dPoints) {
        x_map[point.first]++;
        y_map[point.second]++;
    }
    
    for(auto point : all2dPoints) {
        int x_count = x_map[point.first];
        int y_count = y_map[point.second];
        count += (x_count - 1) * (y_count - 1);
    }
    
    return count;
    
}

int main() {
    
    vector< pair <int,int> > all2dPoints{
        {1, 2},
        {2, 0},
        {2, 2},
        {2, 3},
        {4, 2},
    };
        
    int result = numberOfTriangles(all2dPoints);
    cout<<"\nNumber of triangles = "<<result;
    
    return 0;
}
