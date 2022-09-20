/*******************************************************************
The possible sequences of selected buildings is either "101" or "010".

If the current building is '0', then the number of sequences of pattern 
"101" will be the product of the number of occurances of building '1' 
before the current building to the number of occurances of building '1' 
after the current building and viceversa.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    long long numberOfWays(string s) {

        // count frequency of '0' and '1'
        // so, vector size is just 2
        vector<long long> leftFreq(2, 0);
        vector<long long> rightFreq(2, 0);

        for(char ch : s) {
            int digit = ch - '0';
            rightFreq[digit]++;
        }

        long long result = 0;
        for(int i=0; i<s.length(); i++) {

            // get current digit and alt digit
            int digit = s[i] - '0';
            int altDigit = (digit == 0 ? 1 : 0);

            // remove from right freq map
            rightFreq[digit]--;

            // calculate combinations
            long long leftAltCount = leftFreq[altDigit];
            long long rightAltCount = rightFreq[altDigit];
            result += (leftAltCount * rightAltCount);

            // add to left freq map
            leftFreq[digit]++;
        }

        return result;
    }
};