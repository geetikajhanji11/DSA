/*******************************************************************
https://www.youtube.com/watch?v=toYgBIaUdfM&ab_channel=TECHDOSE

t % 60 gets the remainder from 0 to 59.
We count the occurrence of each remainders in a array/hashmap c.

we want to know that, for each t,
how many x satisfy (t + x) % 60 = 0.

The straight forward idea is to take x % 60 = 60 - t % 60,
which is valid for the most cases.
But if t % 60 = 0, x % 60 = 0 instead of 60.

One solution is to use x % 60 = (60 - t % 60) % 60,
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********** OPTIMIZED GENERAL SOLUTION **********
class Solution {
    
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainderCount(60, 0);
        for(int t : time) {
            remainderCount[t % 60]++;
        }

        int pairs = 0;
        for(int t : time) {

            // exclude the current remainder count
            // from the map so as to not count itself as pair
            remainderCount[t % 60]--;

            // find the complement number for
            // the current number
            int complement = 60 - (t % 60);

            // add this to result if the remainder 
            // value exists (x % 60) = (60 - t % 60) % 60
            pairs += remainderCount[complement % 60];
        }

        return pairs;
    }
};  

// ********** MY SOLUTION **********
class Solution {
    
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        vector<int> multiples60;

        for(int i=1; i*60 <= 1000; i++) {
            multiples60.push_back(i * 60);
        }
        
        unordered_map<int, int> count;
        for(int t : time) count[t]++;

        int pairs = 0;

        for(int i=0; i<time.size(); i++) {

            count[time[i]]--;

            for(int multiple : multiples60) {
                int complement = multiple - time[i];
                pairs += count[complement];
            }

        }

        return pairs;
    }
};  