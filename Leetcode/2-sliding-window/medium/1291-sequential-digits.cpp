/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // reference string
    string digits = "123456789";

    // returns the number of digits
    // of a number
    int digitCount(int num) {
        int ctr = 0;
        while(num != 0) {
            ctr++;
            num = num / 10;
        }
        return ctr;
    }

    // returns true if num is in range
    bool inRange(int &num, int &low, int &high) {
        return low <= num && num <= high;
    }

public:
    vector<int> sequentialDigits(int low, int high) {

        // get number of digits of both
        // low and high, to find the range
        // of groupSize
        int lowDigits = digitCount(low);
        int highDigits = digitCount(high);
        
        vector<int> result;
        int groupSize = lowDigits;
        while(groupSize <= highDigits) {

            // number cannot be 10 digit long
            // as it will go out of bounds
            if(groupSize == 10) break; 

            // get all numbers of current groupsize
            for(int i=0; i<=digits.length()-groupSize; i++) {
                string group = digits.substr(i, groupSize);
                int number = stoi(group);
                if(inRange(number, low, high)) {
                    result.push_back(number);
                }
            }

            // increase group size
            groupSize++;
        }

        return result;
    }
};