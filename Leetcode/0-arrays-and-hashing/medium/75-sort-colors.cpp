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
void sortColors(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int i = 0;

    while(i <= right) {
        if(nums[i] == 0) {

            // swap left and i 
            int temp = nums[i];
            nums[i] = nums[left];
            nums[left] = temp;

            left++;
            i++;
        }

        else if(nums[i] == 2) {

            // swap i and right
            int temp = nums[i];
            nums[i] = nums[right];
            nums[right] = temp;
            
            right--;
        }

        else {
            i++;
        }
    }
}

int main() {

    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    return 0;
}