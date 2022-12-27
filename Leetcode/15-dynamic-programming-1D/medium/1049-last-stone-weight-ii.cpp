/*******************************************************************
Let's take an example with stones = [a,b,c,d], such that the optimal 
solution has the following operations:
    x = a - b -> stones = [x, c, d]
    y = c - d -> stones = [x, y]
    z = x - y -> stones = [z], where z is the smallest possible weight.

We can then write the optimal solution z in the following form:
z = x - y = a - b - (c - d) = (a + d) - (b + c)

This leads us to observe that we can write any optimal solution as 
the difference between two sums. In this case:
X = a + d
Y = b + c
So we have X - Y = z and we also know that X + Y = sum.

We can then say that z = X - Y = sum - Y - Y = sum - 2Y.
So if we want to minimize the solution z, we need to minimize sum - 2Y.
This means Y needs to be as close to sum/2 as possible, without exceeding it.

We can find a sum Y that satisifies this with dynamic programming.
The solution will then be z = X - Y = sum - 2 * Y.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totalSum = accumulate(stones.begin(), stones.end(), 0);

        vector<bool> dp(totalSum/2 + 1, false);
        dp[0] = true;

        int maxSumSoFar = 0;
        for(int stone : stones) {
            vector<bool> temp = dp;
            for(int sum=stone; sum<=totalSum/2; sum++) {
                if(dp[sum - stone]) {
                    temp[sum] = true;
                    if(sum == totalSum / 2) return totalSum - 2 * sum;
                    maxSumSoFar = max(maxSumSoFar, sum);

                }
            }

            dp = temp;
        }

        return totalSum - 2 * maxSumSoFar;

    }
};