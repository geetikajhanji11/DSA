/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_set<int> s;
    int i2 = 0;
    int num1 = 0;
    vector<int> result;
    for(int i=0; i<nums.size(); i++) {
        int num = nums[i];
        int diff = target - num;
        if(s.find(diff) != s.end()) {
            i2 = i;
            num1 = diff;
            result.push_back(i2);
            break;
        }
        s.insert(num);
    }        

    for(int i=0; i<i2; i++) {
        if(nums[i] == num1) {
            result.push_back(i);
            break;
        }
    }
    return result;
}

int main() {

    return 0;
}