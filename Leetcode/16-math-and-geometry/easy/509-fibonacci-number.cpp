/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        
        if(n == 0) return 0;
        if(n == 1) return 1;

        int n1 = 0;
        int n2 = 1;
        int sum = n1 + n2; 

        while(n > 2) {
            n1 = n2;
            n2 = sum;
            sum = n1 + n2;

            n--;
        }

        return sum;
    }
};