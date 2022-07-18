/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = 1;

    int curr_sum = 0;
    for(int num : nums) {
        curr_sum += num;
        int diff = curr_sum - k;
        if(prefix_sum.find(diff) != prefix_sum.end()) {
            result += prefix_sum[diff];
        } 
        prefix_sum[curr_sum]++;
    }
} 

int main() {

    return 0;
}