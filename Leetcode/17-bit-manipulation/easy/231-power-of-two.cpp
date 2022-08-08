/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// WITHOUT LOOP
bool isPowerOfTwo(int n) {
    return n > 0 && ((n & (n - 1)) == 0);
}

// WITH LOOP
bool isPowerOfTwo(int n) {

    if(n < 0) return false;

    bool found_one = false;
    for(int i=0; i<32; i++) {
        int last_bit = n & 1;
        if(last_bit == 1) {
            if(found_one) return false;
            else found_one = true;
        }
        n = n>>1;
    }
    return found_one;
}

int main() {

    return 0;
}