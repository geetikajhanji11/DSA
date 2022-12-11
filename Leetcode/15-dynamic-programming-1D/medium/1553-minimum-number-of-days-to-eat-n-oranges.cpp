/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int minimumDays(int n, unordered_map<int, int> &dp) {
        
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(dp.find(n) != dp.end()) return dp[n];
        
        int days1 = 1 + (n % 2) + minimumDays(n/2, dp);
        int days2 = 1 + (n % 3) + minimumDays(n/3, dp);
        
        return dp[n] = min(days1, days2);

    }

public:
    int minDays(int n) {
        unordered_map<int, int> dp;
        return minimumDays(n, dp);
    }
};