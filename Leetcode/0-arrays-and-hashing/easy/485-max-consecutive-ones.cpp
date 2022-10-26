/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int result = 0;
        int ones = 0;

        for(int num : nums) {
            if(num == 0) {
                result = max(result, ones);
                ones = 0;
            } else {
                ones++;
            }
        }
        
        result = max(result, ones);

        return result;
    }
};