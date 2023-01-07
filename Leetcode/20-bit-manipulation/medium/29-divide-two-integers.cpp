/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long dvd = labs(dividend);
        long dvs = labs(divisor); 
        long ans = 0;

        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

        while (dvd >= dvs) {

            // multiply divisor by 2 each time
            // by doing divisor = divisor << 1;
            long temp_dvs = dvs;
            long m = 1;
            while (dvd >= temp_dvs << 1) {
                temp_dvs = temp_dvs << 1;
                m = m << 1;
            }

            dvd -= temp_dvs;
            ans += m;
        }
        
        return sign * ans;
    }
};