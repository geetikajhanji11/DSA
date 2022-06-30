/*******************************************************************
 * REPLACE BITS IN N BY M
 * 
 * You are given two 32-bit numbers, N and M, and two bit positions
 * i and j. Write a method to set all bits between i and j in N
 * equal to M. M becomes a substring of N locationed at and starting
 * at j.
 * 
 * Example:
 *      N = 1000000000 (512), 10101010101 (1365)
 *      M = 10101 (21), 101111 (47)
 *      i = 2, j = 6
 * 
 *      Output = 100[10101]00 (596), 101[101111]01 (1469)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void clear_ith_bit(int &num, int i) {
   int mask = ~(1<<i);
   num = num & mask;
}

int replace_bits(int N, int M, int i, int j) {
    for(int pos=i; pos<=j; pos++) {
        clear_ith_bit(N, pos);
    }
    int mask = M<<i;
    int ans = N | mask;
    return ans;
}

int main() {

    int ans = replace_bits(15, 2, 1, 3);
    cout<<ans;
    return 0;
}