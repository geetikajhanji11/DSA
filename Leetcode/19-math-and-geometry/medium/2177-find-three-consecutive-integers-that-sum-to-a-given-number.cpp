/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        // equation is: n + (n + 1) + (n + 2) = num
        // 3n + 3 = num
        // n + 1 = num / 3
        // n = (num / 3) - 1

        if(num % 3 != 0) return {};

        long long n = (num / 3) - 1;

        return {n, n+1, n+2};
    }
};