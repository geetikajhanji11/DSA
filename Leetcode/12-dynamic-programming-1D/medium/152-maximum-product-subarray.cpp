/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int currMax = nums[0];
    int currMin = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        int a = currMax * nums[i];
        int b = currMin * nums[i];
        currMax = max(max(a, b), nums[i]);
        currMin = min(min(b, a), nums[i]);
        
        result = max(result, currMax);
    }
    
    return result;
}

int main() {

    return 0;
}