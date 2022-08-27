/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// *********** TOP-DOWN APPROACH ***********
class Solution {
public:

    int maxProduct(int n, int &target, vector<int> &dp) {
        if(n == 1) return 1;
        
        if(dp[n] != -1) return dp[n];

        int ans = (n == target) ? 0 : n;
        for(int i=1; i<n; i++) {
            int product = maxProduct(i, target, dp) * maxProduct(n-i, target, dp);
            ans = max(ans, product);
        }

        return dp[n] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return maxProduct(n, n, dp);
    }
};

// *********** BOTTOM-UP APPROACH ***********
class Solution {
public:

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);

        dp[1] = 1;

        int target = n;

        for(int n=2; n<=target; n++) {
            int ans = (n == target) ? 0 : n;
            for(int i=1; i<n; i++) {
                int product = dp[i] * dp[n-i];
                ans = max(ans, product);
            }
            dp[n] = ans;
        }

        return dp[target];
    }
};