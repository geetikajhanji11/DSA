/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int leastBricks(vector<vector<int>>& wall) {

    // key = position of gap
    // value = total number of gaps at this pos in entire wall 
    unordered_map<int, int> countGap; 

    for(vector<int> row : wall) {
        int pos = 0;
        for(int i=0; i<row.size()-1; i++) {
            pos += row[i];
            countGap[pos]++;
        }
    }

    int maxGapCount = 0;
    for(auto element : countGap) {
        maxGapCount = max(maxGapCount, element.second);
    }

    // (all_rows - gaps) = number of bricks crossed
    return wall.size() - maxGapCount;
}

int main() {

    return 0;
}