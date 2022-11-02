/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// MATH
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int maxPowerOfThree = pow(3, 19);
        return maxPowerOfThree % n == 0;
    }
};

// LOOP / RECURSION
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) n = n / 3;
        return n == 1;
    }
};