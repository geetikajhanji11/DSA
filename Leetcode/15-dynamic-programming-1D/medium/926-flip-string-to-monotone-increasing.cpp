/*******************************************************************
EXPLANATION FOR MY SOLUTION

Treat every ith position of the string as the beginning of the 
11111... sequence, before and at which every position is 0000...
[the ith is 0 itself and 1111... seq starts from (i+1)th]

At ith position, [0, i] should be "0" and [i+1, n-1] should be 1.
So, the formula for number of flips will be

flips = number of 1's before ith position + 
            number of 0's after ith position

The ith position itself should also be 0, so if it is 1, we will
add 1 to "flips". If it is 0 only, no change. SO, overall formula 
becomes:

flips = number of 1's before ith position + 
            number of 0's after ith position + 
                digit at ith position (1 or 0)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** DISCUSS SOLUTION ***************
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int result = 0;

        int preceedingOnes = 0;
        for(int i=0; i<s.length(); i++) {

            int digit = s[i] - '0';

            // if digit is 1, then it will not inpact the minFlips
            if(digit == 1) preceedingOnes++;
            
            // if digit is 0, then 2 options
            else {

                // 1. [keep it as 0]
                // by flipping all the preceeding 1 to 0
                int op1 = preceedingOnes;

                // 2. [flip it to 1]
                // a flip will cause + 1
                int op2 = result + 1;

                result = min(op1, op2);
            }
        }
        return result;
    }
};

// *************** MY SOLUTION ***************
class Solution {
public:
    int minFlipsMonoIncr(string s) {
       
        vector<int> leftFreq(2, 0);
        vector<int> rightFreq(2, 0);

        for(char ch : s) {
            int digit = ch - '0';
            rightFreq[digit]++;
        }

        // case for "1111111"
        int result = leftFreq[1] + rightFreq[0];

        // cases for 
        // "01....", 
        // "001...", 
        // "0001..." 
        // ... 
        // "0000000" 
        for(char ch : s) {
            int digit = ch - '0';
            rightFreq[digit]--;

            int flips = leftFreq[1] + rightFreq[0] + digit;
            result = min(result, flips);

            leftFreq[digit]++;
        }

        return result;
    }
};