/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int canShip(vector<int>& weights, int days, int minCapacity) {
        
        int daysCount = 1;
        int currCapacity = 0;

        for(int weight : weights) {
            if(currCapacity + weight > minCapacity) {
                currCapacity = 0;
                daysCount++;
            }
            currCapacity += weight;

            // edge case in which a single weight only
            // is greater than minCapacity, then everytime
            // daysCount > days
            if(currCapacity > minCapacity) return 1;
        }

        // it is taking more days to ship with this mincapacity
        // increase mincapacity
        if(daysCount > days) return 1;

        // it is taking less days to ship with this mincapacity
        // decrease mincapacity
        if(daysCount < days) return -1;

        return 0; // equal

    }


public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = accumulate(weights.begin(), weights.end(), 0);

        int result = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            int x = canShip(weights, days, mid);

            if(x == 0) {
                result = min(result, mid);
                high = mid - 1;
            } else if(x == 1) {
                low = mid + 1;
            } else if(x == -1) {
                result = min(result, mid);
                high = mid - 1;
            }
        }

        return result;

    }
};