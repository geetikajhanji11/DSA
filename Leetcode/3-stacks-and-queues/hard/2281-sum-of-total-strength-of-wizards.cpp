/*******************************************************************

...left-1, left, [left+1, left+2, ... i-1, (i), i+1, ... right-1]. right, right+1...


The sum of subarrays including i as minimum element are:


the subarrays that start with left+1:
=====================================
sum(left+1, ... i) = prefix[i + 1] - prefix[left + 1]
sum(left+1, ... i+1) = prefix[i + 2] - prefix[left + 1]
...
sum(left+1, ... right-1) = prefix[right] - prefix[left + 1]


the subarrays that start with left+2:
=====================================
sum(left+2, ... i) = prefix[i + 1] - prefix[left + 2]
sum(left+2, ... i+1) = prefix[i + 2] - prefix[left + 2]
...
sum(left+2, ... right-1) = prefix[right] - prefix[left + 2]
...


the subarrays that start with i:
=====================================
sum(i, ... i) = prefix[i + 1] - prefix[i]
sum(i, ... i+1) = prefix[i + 2] - prefix[i]
...
sum(i, ... right-1) = prefix[right] - prefix[i]


Then we combine all above terms, we have:


positive parts:
===============
(prefix[i + 1] + prefix[i + 2] + ... + prefix[right]) * (i - left)

negative parts:
===============
(prefix[left + 1] + prefix[left + 2] + ... + prefix[i]) * (right - i)


The range sum of prefix can be optimized by pre-compute prefix-sum of prefix.
Time complexity: O(N): we have 5 passes of the input array length
Space complexity: O(N): two prefix arrays and a stack (vector) is used
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int MOD = pow(10, 9) + 7;
public:
    int totalStrength(vector<int>& st) {
        const int N = st.size();

        // sum of first k elements
        vector<long long> prefix(N + 1, 0L);
        for (int i = 0; i < N; ++i) {
            prefix[i + 1] = (prefix[i] + st[i]) % MOD;
        }

        // sum of first k prefix
        vector<long long> prefix_sum(N + 2, 0L);
        for (int i = 0; i <= N; ++i) {
            prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
        }
        
        // first index on the left < current st
        vector<int> left(N, -1);
        
        // mono increase
        vector<int> stack;
        for (int i = 0; i < N; ++i) {
            while (!stack.empty() && st[stack.back()] >= st[i]) {
                stack.pop_back();
            }
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }
        
        // first index on the right <= current st
        vector<int> right(N, N);
        stack.clear();
        for (int i = N - 1; i >= 0; --i) {
            while (!stack.empty() && st[stack.back()] > st[i]) {
                stack.pop_back();
            }
            right[i] = stack.empty() ? N : stack.back();
            stack.push_back(i);
        }
        
        long long res = 0;
        for (int i = 0; i < N; ++i) {
            res += ((prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % MOD + MOD * 2 - 
                (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % MOD) % MOD * st[i] % MOD;
            res %= MOD;
        }
        return (int) res;
    }
};