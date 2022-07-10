/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    for(int i=0; i<n; i++) {

        // handle duplicate
        if(i-1 >= 0 && nums[i] == nums[i-1]) continue;

        int num = nums[i];
        int sum_to_find = target - num;

        int left = i+1;
        int right = n-1;

        while(left < right) {
            
            // handle duplicate
            while(left-1>i && left<n && nums[left] == nums[left-1]) left++;
            while(right+1<n && right>=0 && nums[right] == nums[right+1]) right--;

            if(left >= right) break;

            int curr_sum = nums[left] + nums[right];
            if(curr_sum == sum_to_find) {
                vector<int> found;
                found.push_back(num);
                found.push_back(nums[left]);
                found.push_back(nums[right]);
                result.push_back(found);
                left++;
                right--;
            }
            else if(curr_sum < sum_to_find) {
                left++;
            } else {
                right--;
            }
        }

    }

    return result;
}

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4}; // {-2,0,0,2,2};
    auto result = threeSum(nums);
    for(auto v : result) {
        for(int num : v) cout<<num<<", ";
        cout<<endl;
    }
    return 0;
}