/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int num1 = -1;
        int num2 = -1;

        int ctr1 = 0;
        int ctr2 = 0;

        for(int num : nums) {

            if(num1 == num) {
                ctr1++;
            } 
            else if(num2 == num) {
                ctr2++;
            } 
            else if(ctr1 == 0) {
                num1 = num;
                ctr1 = 1;
            } 
            else if(ctr2 == 0) {
                num2 = num;
                ctr2 = 1;
            } 
            else {
                ctr1--;
                ctr2--;
            }
        }

        ctr1 = 0;
        ctr2 = 0;

        for(int num : nums) {
            if(num1 == num) ctr1++;
            else if(num2 == num) ctr2++;
        }

        vector<int> result;
        if(ctr1 > ceil(nums.size() / 3)) {
            result.push_back(num1);
        }
        if(ctr2 > ceil(nums.size() / 3)) {
            result.push_back(num2);
        }

        return result;
    }
};