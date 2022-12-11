/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double power(double x, int n) {
    if(n == 0) return 1;
    if(n == 1) return x;

    // power is even
    if(n % 2 == 0) {
        double halfPow = myPow(x, n/2);
        return halfPow * halfPow;
    }   

    // power is odd
    double halfPow = myPow(x, n/2);
    return x * halfPow * halfPow;
}

double myPow(double x, int n) {

    if(x == 1) return x;
        
    bool is_number_negative = x < 0;
    bool is_negative = n < 0;

    double ans;
    if(is_negative) {
        if(n == INT_MIN) {
            ans = 1 / (power(x, -(n+1)));
        }
        else {
            ans = 1 / (power(x, n * (-1)));
        }
    } else {
        ans = power(x, n);
    }

    if(is_number_negative && n % 2 == 0) {
        if(ans < 0) ans = ans * (-1);
    }
    return ans;
}

int main() {

    return 0;
}