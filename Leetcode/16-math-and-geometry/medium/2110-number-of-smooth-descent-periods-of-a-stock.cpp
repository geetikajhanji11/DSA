/*******************************************************************
[(3,2,1),(10),(34),(5,4,3,2,1)]

=> [3,2,1] (3)
 * 3,2,1
 * 3,2
 * 3

=> [10] (1)
 * 10

=> [34] (1)
 * 34

=> [5,4,3,2,1] (5)
 * 5,4,3,2,1
 * 5,4,3,2
 * 5,4,3
 * 5,4
 * 5

Total = 3 + 1 + 1 + 5 = 10
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0;

        int left = 0;
        int right = 0;

        while(right < prices.size()) {
            
            // find decreasing array
            while(right+1 < prices.size() && prices[right] - 1 == prices[right+1]) {
                right++;
            }

            // get size of this subarray
            // count += (n * (n + 1)) / 2;
            int n = right - left + 1; 
            count += (n % 2 == 0 ? ((long long)(n / 2) * (n + 1)) : ((long long)((n + 1) / 2) * n));

            // reset subarray extremes
            left = right + 1;
            right = left;
        }

        return count;
    }
};