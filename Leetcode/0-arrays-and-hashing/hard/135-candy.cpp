/*******************************************************************
The left2right array is used to store the number of candies 
required by the current student taking care of the distribution 
relative to the left neighbors only.
    i.e. Assuming the distribution rule is: 
        The student with a higher rating than their left neighbor 
        should always get more candies than its left neighbor.

The right2left array is used to store the number of candies 
required by the current student taking care of the distribution 
relative to the right neighbors only. 
    i.e. Assuming the distribution rule to be: 
        The student with a higher rating than their right neighbor 
        should always get more candies than their right neighbor.

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();

        vector<int> leftToRight(n, 1);
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) {
                leftToRight[i] = leftToRight[i-1] + 1;
            } 
        }

        vector<int> rightToLeft(n, 1);
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                rightToLeft[i] = rightToLeft[i+1] + 1;
            }
        }

        int candies = 0;
        for(int i=0; i<n; i++) {
            candies += max(leftToRight[i], rightToLeft[i]);
        }

        return candies;
    }
};
