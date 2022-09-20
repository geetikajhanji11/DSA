/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int n = nums.size();

        int maxLen = 0;

        int negativeNumbers = 0;
        int negIdx1 = -1; // first negative number index
        int negIdx2 = -1; // last negative number index

        // start and end of current array
        // rightIdx always points at 0 or n (when array ends)
        int leftIdx = 0; 
        int rightIdx = 0;

        for(int i=0; i<=n; i++) {

            // treat it as end of an array
            // reset values
            if(i == n || nums[i] == 0) {

                // if we have even number of negative numbers in current
                // subarray, we simply check current subarray's length
                if(negativeNumbers % 2 == 0) {
                    maxLen = max(maxLen, rightIdx - leftIdx);
                } 
                
                // if we have odd numbers of negative numbers in current
                // subarray, we need to check lengths of two divided 
                // subarrays of this subarray obtained after:
                // 1. Removing the last negative number
                // 2/ Removing the first negative number
                else {

                    // get total length of the subarray
                    int totalLength = rightIdx - leftIdx;

                    // remove the last negative number from current subarray
                    // len1 = negIdx2 - leftIdx;
                    int len1 = totalLength - (rightIdx - negIdx2);

                    // remove the first negative number from current subarray
                    // len2 = rightIdx - negIdx1 - 1;
                    int len2 = totalLength - (negIdx1 - leftIdx + 1);

                    // check who's length is greater
                    maxLen = max(maxLen, max(len1, len2));
                }

                // reset all variables
                leftIdx = i + 1;
                rightIdx = i + 1;
                negativeNumbers = 0;
                negIdx1 = -1;
                negIdx2 = -1;
                continue;
            }

            // increment count of neg numbers in current subarray
            if(nums[i] < 0) {
                negativeNumbers++;
                if(negIdx1 == -1) { 
                    negIdx1 = i;
                }
                negIdx2 = i;
            }
            
            // increment size of current subarray
            rightIdx++;
        }

        return maxLen;
    }
};