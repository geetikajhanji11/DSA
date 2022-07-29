/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0;
    int j = 0;

    while(j < nums.size()) {
        while(j < nums.size() && nums[j] == val) j++;
        if(j < nums.size() && nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }       
    return i; 
}

int main() {

    return 0;
}