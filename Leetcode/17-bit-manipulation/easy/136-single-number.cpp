/*******************************************************************
Given int array, every element appears twice except 1, find it
Ex. nums = [2,2,1] -> 1, nums = [4,1,2,1,2] -> 4

a XOR a returns 0, so returns 0 for all except the unique one

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int total_xor = 0;
    for(int num : nums) {
        total_xor = total_xor ^ num;
    }        
    return total_xor;
}

int main() {

    return 0;
}