/*******************************************************************
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        // Get its last set bit
        diff &= -diff;

        vector<int> rets = {0, 0}; 
        for (int num : nums) {
            if ((num & diff) == 0) {
                rets[0] ^= num;
            }
            else // the bit is set {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int findIthBit(int num, int i) {
        int mask = 1 << i;
        int x = mask & num;
        if(x == 0) return 0;
        return 1;
    }

public:
    vector<int> singleNumber(vector<int>& nums) {
        
        // take XOR of all numbers
        // the resultant XOR will be XOR
        // of the two single numbers
        int num1_num2_xor = 0;
        for(int num : nums) {
            num1_num2_xor = num1_num2_xor ^ num;
        }

        // find the position as which the resultant
        // XOR has a bit = 1 (since at this position,
        // the two single numbers are different)
        int pos = 0;
        for(int i=0; i<32; i++) {
            int bit = findIthBit(num1_num2_xor, i);
            if(bit == 1) {
                pos = i;
                break;
            }
        }

        // divide the numbers into 2 groups
        // and take their xors
        int xor_1 = 0;
        int xor_2 = 0;
        for(int num : nums) {
            int ithBit = findIthBit(num, pos);

            // group1 => ith bit = 0
            if(ithBit == 0) xor_1 = xor_1 ^ num;
            
            // group2 => ith bit = 1
            else xor_2 = xor_2 ^ num;
            
        }

        // return result
        vector<int> result;
        result.push_back(xor_1);
        result.push_back(xor_2);
        
        return result;
    }
};