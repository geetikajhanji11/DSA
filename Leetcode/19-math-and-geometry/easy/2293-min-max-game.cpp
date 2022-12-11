/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();

        while(n != 1) {

            int idx = 0;
            bool minTurn = true;
            for(int i=0; i<n; i=i+2) {
                if(minTurn) {
                    nums[idx] = min(nums[i], nums[i+1]);
                } else {
                    nums[idx] = max(nums[i], nums[i+1]);
                }
                minTurn = !minTurn;
                idx++;
            }
            n = n / 2;
        }

        return nums[0];
    }
};