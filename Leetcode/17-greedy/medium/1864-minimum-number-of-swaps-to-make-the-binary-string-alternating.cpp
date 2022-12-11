/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isEven(int &num) {
        return num % 2 == 0;
    }

    pair<int, int> outOfPlaceCount(string &s) {

        int n = s.length();

        int ctr0 = 0; // for pattern "01010101..."
        int ctr1 = 0; // for pattern "10101010..."

        // keep count of 1's and 0's
        // in entire string
        int ones = 0;
        int zeroes = 0;

        for(int i=0; i<n; i++) {

            // check for misplaced character
            // at even position
            if(i % 2 == 0) {
                if(s[i] == '0') { // misplaced for pattern "1010.."
                    ctr1++;
                    zeroes++;
                } else { // misplaced for pattern "0101.."
                    ctr0++;
                    ones++;
                }
            } 
            
            // check for misplaced character
            // at odd position
            else {
                if(s[i] == '0') { // misplaced for pattern "0101.."
                    ctr0++;
                    zeroes++;
                } else { // misplaced for pattern "1010.."
                    ctr1++;
                    ones++;
                }
            }
        }

        // is string length is even, 
        // for answer to be valid, number of 1's and 0's
        // must be equal. If not equal, return an invalid answer
        if(isEven(n)) {
            if(ones != zeroes) return {1, 1};
        } 
        
        // if string length is odd,
        // for answer to be valid, two possibilities are there:
        // 1) ones = 1 + zeroes
        // 2) zeroes = 1 + ones
        // any other possibility means that it is impossible
        // to make string alternating, so return an invalid answer 
        else {
            if(abs(ones - zeroes) != 1) return {1, 1};
        }

        // return actual answer
        return {ctr0, ctr1};
    }

public:
    int minSwaps(string s) {
        auto p = outOfPlaceCount(s);

        int ctr0 = p.first;
        int ctr1 = p.second;

        int result = INT_MAX;

        // check for min answer only if count is even
        if(isEven(ctr0)) {
            result = min(result, ctr0 / 2);
        }

        // check for min answer only if count is even
        if(isEven(ctr1)) {
            result = min(result, ctr1 / 2);
        }

        // both are counts are odd,
        // impossible to make string alternating
        if(result == INT_MAX) {
            result = -1;
        }

        return result;
    }
};