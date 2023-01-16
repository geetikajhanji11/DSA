/*******************************************************************
class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int l = 0;
    int r = nums.size();

    // # of missing numbers in [nums[0], nums[i]]
    auto nMissing = [&](int i) { return nums[i] - nums[0] - i; };

    // Find the first index l s.t. nMissing(l) >= k
    while (l < r) {
      const int m = (l + r) / 2;
      if (nMissing(m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return nums[l - 1] + (k - nMissing(l - 1));
  }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int missingNumberCount(int i, vector<int> &nums) {
        int leftIdx = 0;
        int rightIdx = i;

        int noOfElementsPresent = rightIdx - leftIdx + 1;
        int noOfElementsShouldBePresent = nums[rightIdx] - nums[leftIdx] + 1;

        return noOfElementsShouldBePresent - noOfElementsPresent;
    } 

    int missingElement(vector<int> nums, int k) {
        int low = 0;
        int high = nums.size() - 1;

        // Find the first index "low" where nMissing(low) >= k
        while(low < high) {
            int mid = (low + high) / 2;

            int noOfmissing = missingNumberCount(mid, nums); 
       
            if(noOfmissing >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }

        }

        return nums[low-1] + (k - missingNumberCount(low-1, nums));
    }
};