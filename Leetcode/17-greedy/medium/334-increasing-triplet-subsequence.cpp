/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int smallest = INT_MAX;
        int middle = INT_MAX;

        for(int num : nums) {

            // smallest number so far or the lowest point of our sequence.
            if(num <= smallest) {
                smallest = num;
            } 
            
            // greater than smallest number or the middle point so far.
            else if(num <= middle) {
                middle = num;
            } 
            
            // we've found a number that was not smaller than the middle.
            // this number must be larger than both. We've found our triplet.
            else {
                return true;
            }
        }

        return false;
    }
};