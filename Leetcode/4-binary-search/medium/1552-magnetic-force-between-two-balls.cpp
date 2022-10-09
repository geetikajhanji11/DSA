/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool canPlace(vector<int>& position, int minForce, int &target) {
        
        int balls = 1;
        int lastBallPos = position[0];

        // count balls that can be placed 
        // where there is "minForce" force b/w any two balls
        for(int i=1; i<position.size(); i++) {
            if(position[i] - lastBallPos >= minForce) {
                balls++;
                lastBallPos = position[i];
            }
        }

        return balls >= target;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 0;
        int high = position[position.size()-1] - position[0]; 

        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canPlace(position, mid, m)) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};