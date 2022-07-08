/*******************************************************************
 * CLEAR LAST i BITS
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int clear_last_i_bits(int num, int i) {
    // METHOD-1
    // right shift i times, 
    // then left shift i times
    int new_num = num>>i;
    new_num = new_num<<i; // 448 (111000000)

    // METHOD-2
    int mask = (~0)<<i;
    int ans = mask & num; //448 (111000000)
    return ans; 
}

int main() {

    int n = 511; // 111111111
    int i = 6;

    int ans = clear_last_i_bits(n, i); 
    cout<<"\n\tAfter clearing last "<<i<<" bits = "<<ans;

    return 0;
}