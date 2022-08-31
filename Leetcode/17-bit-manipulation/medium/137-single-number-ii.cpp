/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // returns bit at position 1 for num
    bool findIthBit(int num, int i) {
        int mask = 1 << i;
        int arb = mask & num;
        if(arb == 0) return 0;
        return 1;
    }

public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> count1Bits(32, 0);

        // count the number of "1" bits
        // at position i
        for(int num : nums) {
            for(int i=0; i<32; i++) {
                int bit = findIthBit(num, i);
                if(bit == 1) {
                    count1Bits[i]++;
                }
            }
        }

        // if ith position has number of 1 bits
        // which are NOT multiple of 3, then the
        // result number's 1 bit must have been 
        // at this position
        int number = 0;
        for(int i=0; i<32; i++) {
            if(count1Bits[i] % 3 != 0) {
                number += (1 << i);
            }
        }

        return number;

    }
};