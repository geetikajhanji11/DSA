#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*

Given n non-negative integers representing an
elevation map where width of each bar is 1, 
compute how much water it can trap after raining

*/

int rainwaterTrap(vector<int> heights) {

    int result = 0;

    int n = heights.size();
    if(n <= 2) return 0;

    vector<int> leftMaxHeight(n, 0);
    vector<int> rightMaxHeight(n, 0);

    leftMaxHeight[0] = heights[0];
    rightMaxHeight[n-1] = heights[n-1];
    
    // calculating left max hights
    for(int i=1; i<n; i++) {
        int h = max(heights[i], leftMaxHeight[i-1]);
        leftMaxHeight[i] = h;
    }

    // calculating right max hights
    for(int i=n-1; i>=1; i--) {
        int h = max(heights[i-1], rightMaxHeight[i]);
        rightMaxHeight[i-1] = h;
    }

    for(int i=0; i<heights.size(); i++) {

        int unitOfWater = min(leftMaxHeight[i], rightMaxHeight[i]) - heights[i];
        if(unitOfWater < 0) continue;
        result += unitOfWater;
    }

    return result;
}


int main() {

    vector<int> heights {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	
    int result = rainwaterTrap(heights);
    cout<<"\nUnits of water = "<<result;
    

    return 0;
}
