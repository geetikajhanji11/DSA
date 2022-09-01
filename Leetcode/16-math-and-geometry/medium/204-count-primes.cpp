/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        
        if(n <= 1) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int num=2; num<sqrt(n); num++) {

            // current number is a prime number
            if(isPrime[num]) {
                // mark all the multiples of this
                // prime number as false
                int factor = 2;
                while(factor * num < n) {
                    isPrime[factor * num] = false;
                    factor++;
                }
            }
        }

        int ctr = 0;
        for(bool booleanVal : isPrime) ctr += booleanVal;
        return ctr;
    }
};