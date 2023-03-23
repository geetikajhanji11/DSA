/*******************************************************************
permutation

1 digit => 10               (0,1,2,3,4,5,6,7,8,9)
2 digits => _ _ = 9*9     ([1,9], [0,9] - number chosen at first position)
3 digits => _ _ _ = 9*9*8
4 digits => _ _ _ _ = 9*9*8*7
5 digits => _ _ _ _ _ = 9*9*8*7*6
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********* iterative *********
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;

        int sum = 10;
        int ctr = 2;

        int prod = 9;
        int f = 9;
        while(ctr <= n) {
            prod *= f;
            f--;
            sum += prod;
            ctr++; 
        }
        
        return sum;

    }
};

// ********* recursive *********
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;

        int prod = 9;
        for(int i=0; i<n-1; i++) {
            prod *= (9 - i);
        }

        return prod + countNumbersWithUniqueDigits(n-1);

    }
};