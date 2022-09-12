/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);

        // base case
        dp[0] = 1; 
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        // keep using ugly numbers themselves
        // to create new ugly numbers
        for(int i=1; i<n; i++) {

            int multiple_2 = dp[p2] * 2;
            int multiple_3 = dp[p3] * 3;
            int multiple_5 = dp[p5] * 5;

            dp[i] = min(multiple_2, min(multiple_3, multiple_5));

            if(dp[i] == multiple_2) p2++;
            if(dp[i] == multiple_3) p3++;
            if(dp[i] == multiple_5) p5++;
        }

        return dp[n-1];
    }
};