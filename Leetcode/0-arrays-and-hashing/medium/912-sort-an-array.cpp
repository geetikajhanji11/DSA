/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // left = [start...mid]
    // right = [mid+1...end]
    void merge(int start, int mid, int end, vector<int> &nums) {
        if(start >= end) return;
        
        vector<int> num3(mid - start + 1 + end - mid + 1);

        int i = start;
        int j = mid + 1;
        int k = 0;

        while(i <= mid && j <= end) {
            if(nums[i] < nums[j]) {
                num3[k] = nums[i];
                k++;
                i++;
            } else {
                num3[k] = nums[j];
                k++;
                j++;
            }
        }

        while(i <= mid) {
            num3[k] = nums[i];
            k++;
            i++;
        }

        while(j <= end) {
            num3[k] = nums[j];
            k++;
            j++;
        }

        k = 0;
        for(int idx=start; idx<=end; idx++) {
            nums[idx] = num3[k];
            k++;
        }
    
    }


    void mergeSort(int i, int j, vector<int> &nums) {
        if(i >= j) return ;

        int mid = (i + j) / 2;
        mergeSort(i, mid, nums);
        mergeSort(mid+1, j, nums);
        return merge(i, mid, j, nums);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};