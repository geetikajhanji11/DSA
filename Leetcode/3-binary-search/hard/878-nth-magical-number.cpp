/*******************************************************************
10
2
11

ans = 18
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BINARY SEARCH
// ********  ********
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        int LCM = a / gcd(a, b) * b;

        long low = 0;
        long high = (long) n * min(a, b);

        while(low < high) {

            long mid = low + (high - low) / 2;
            
            // If there are not enough magic numbers below mi...
            if (mid / a + mid / b - mid / LCM < n)
                low = mid + 1;
            else
                high = mid;
        }

        return (int) (low % MOD);
    }

    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
};

// MY SOLUTION
// ******** O(N) => TLE ********
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        
        n--;

        int i_a = 0;
        int i_b = 0;

        while(n >= 0) {
            int next_a = a * (i_a + 1);
            int next_b = b * (i_b + 1);

            int curr;
            if(next_a < next_b) {
                curr = next_a;
                i_a++;
            } else if(next_b < next_a) {
                curr = next_b;
                i_b++;
            } else {
                curr = next_a;
                i_a++;
                i_b++;
            }

            if(n == 0) return curr;
            n--;
        }

        return min(a, b);
    }
};