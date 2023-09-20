/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 2 passes
// void sortColors(vector<int>& nums) {
//     vector<int> count(3);
    
//     for(int num : nums) {
//         count[num]++;
//     }
    
//     int i = 0;
    
//     for(int num=0; num<=2; num++) {
//         while(count[num] != 0) {
//             nums[i] = num;
//             count[num]--;
//             i++;
//         }
//     }
// }

// 1 pass
// {2,0,2,1,1,0};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0; // position for 0
        int i = 0;
        int right = nums.size() - 1; // position for 2

        while(i < right) {
     
            if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                i++;
                left++;
            }

            else if(nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }

            else {
                i++;
            }

            
        }
    }
};
