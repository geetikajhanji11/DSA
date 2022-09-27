/*******************************************************************

0, 1, 2, 3, 4
2, 3, 4, 7, 11
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********** DISCUSS SOLUTION ********** 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high) {

            int mid = (low + high) / 2;

            int numbersMissing = arr[mid] - mid;

            if(numbersMissing <= k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};

// ********** MY SOLUTION ********** 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        int idx = -1;
        int ctr = 0;
        while(low <= high) {
            int mid = (low + high) / 2;

            int numbersMissing = arr[mid] - (mid + 1);
            if(numbersMissing < k) {
                idx = mid;
                low = mid + 1;
                ctr = numbersMissing;
            } else {
                high = mid - 1;
            }
        }

        // case : arr = [4], k = 3
        if(idx == -1) {
            
            int diff = arr[0] - 1;
            if(k <= diff) {
                return k;
            }
            
            idx = 0;
            ctr = diff;
        }
        
        k -= ctr;

        while(idx + 1 < arr.size()) {

            while(idx + 1 < arr.size() && (arr[idx] + 1 == arr[idx+1])) {
                idx++;
            }

            if(idx + 1 < arr.size()) {
                int diff = arr[idx+1] - arr[idx];
                if(diff < k) {
                    k -= diff;
                } else {
                    return arr[idx] + k;
                }
                idx++;
            }
        } 

        return arr[idx] + k;
    }
};