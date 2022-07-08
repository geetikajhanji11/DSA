/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> forward(n, 0);
    vector<int> backward(n, 0);

    forward[0] = 1;
    backward[n-1] = 1;

    // filling forward array
    for(int i=1; i<n; i++) {
        forward[i] = forward[i-1] * nums[i-1];
    }

    // filling backward array
    for(int i=n-2; i>=0; i--) {
        backward[i] = backward[i+1] * nums[i+1];
    }

    vector<int> result(n, 0);
    for(int i=0; i<n; i++) {
        result[i] = forward[i] * backward[i];
    }
    return result;
} 

int main() {

    return 0;
}