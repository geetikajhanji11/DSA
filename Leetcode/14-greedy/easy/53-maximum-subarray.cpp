#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {

    int overall_max = INT_MIN;
    int curr_sum = 0;

    for(int num : nums) {

        curr_sum += num;

        overall_max = max(overall_max, curr_sum);

        if(curr_sum < 0) {
            curr_sum = 0;
        }
    }
    return overall_max;
}

int main() {

    return 0;
}