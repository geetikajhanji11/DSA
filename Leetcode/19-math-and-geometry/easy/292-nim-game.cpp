/*******************************************************************
    public boolean canWinBash(int n) {
        int[] memo = new int[n + 1];
        return helper(n, memo);
    }

    private boolean helper(int n, int[] memo) {

        if (n <= 3) return true;
        if (memo[n] != 0) return memo[n] == 1;

        for (int i = 1; i <= 3; i++) {
            if (!helper(n - i, memo)) {
                memo[n] = 1;
                return true;
            }
        }
        memo[n] = -1;
        return false;
    }



*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
1 - t (1)
2 - t (2)
3 - t (3)

4 - f

5 - t (1)
6 - t (2)
7 - t (3)

8 - f

and so on...

We know, f(1) = f(2) = f(3) = 1;
----------------------------------
f(n)=!(f(n-1) && f(n-2) && f(n-3));
----------------------------------
f(4)=!(1 && 1 && 1)=0;
f(5)=!(0 && 1 && 1)=1=f(6)=f(7);
f(8)=!(1 && 1 && 1)=0;

*/

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};