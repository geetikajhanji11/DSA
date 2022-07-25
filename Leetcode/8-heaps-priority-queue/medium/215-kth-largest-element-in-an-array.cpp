/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



// -------------- HEAP SOLUTION --------------
// O(klogn)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int num : nums) {
        minHeap.push(num);
        if(minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// -------------- QUICKSELECT SOLUTION --------------
int partition(int left, int right, vector<int>& nums) {
    int pivot = nums[left];
    int i = left;
    int j = right;
    while(i < j) {
        while(i <= j && nums[i] <= pivot) i++;
        while(i <= j && nums[j] > pivot) j--;
        if(i < j) swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[j]);
    return j;
}

int findKthLargest(vector<int>& nums, int k) {

    int n = nums.size();
    int target_index = n - k;

    int left = 0;
    int right = nums.size() - 1;

    int pivot_index = n;

    while(pivot_index != target_index) {
        pivot_index = partition(left, right, nums);
        if(target_index < pivot_index) {
            right = pivot_index - 1;
        } else {
            left = pivot_index + 1;
        }
    }

    return nums[target_index];
}



int main() {

    return 0;
}