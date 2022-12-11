/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // peak can never be 0 or n-1
    // -1 => peak lies left of i [1, i-1]
    // 0 => current i is peak
    // 1 => peak lies right of i [i+1, n-2]
    int direction(int i, vector<int>& arr) {
        if(i == 0) return 1;
        if(i == arr.size() - 1) return -1;

        // found the peak
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
            return 0;
        } 
        
        // increasing seq => peak must be right
        else if(arr[i-1] < arr[i] && arr[i] < arr[i+1]) {
            return 1;
        }

        // descreasing seq => peak must be left
        else if(arr[i-1] > arr[i] && arr[i] > arr[i+1]) {
            return -1;
        }

        // no other case, default value
        return -2;
    }

public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        // binary search
        while(low <= high) {
            int mid = (low + high) / 2;

            int dir = direction(mid, arr);

            if(dir == 0) return mid; // found
            else if(dir == -1) high = mid - 1; // go left
            else low = mid + 1; // go right
        
        }

        // could not find peak
        return -1;
    }
};