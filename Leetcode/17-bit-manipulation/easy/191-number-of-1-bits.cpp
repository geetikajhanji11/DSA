#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int ctr = 0;
    while(n != 0) {
        n = n & (n-1);
        ctr++;
    }
    return ctr;
}

int main() {

    return 0;
}