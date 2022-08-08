/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(N)
int maximumProduct(vector<int>& nums) {

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    for (int n: nums) {
        if (n <= min1) {
            min2 = min1;
            min1 = n;
        } else if (n <= min2) {     // n lies between min1 and min2
            min2 = n;
        }
        if (n >= max1) {            // n is greater than max1, max2 and max3
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (n >= max2) {     // n lies betweeen max1 and max2
            max3 = max2;
            max2 = n;
        } else if (n >= max3) {     // n lies betwen max2 and max3
            max3 = n;
        }
    }

    int op1 = max1 * max2 * max3;
    int op2 = max1 * min1 * min2;

    return max(op1, op2);
}

// O(NlogN)
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int all_positive = nums[n-1] * nums[n-2] * nums[n-3];
    int all_negative = nums[n-1] * nums[0] * nums[1];

    return max(all_positive, all_negative);
}

int main() {

    return 0;
}