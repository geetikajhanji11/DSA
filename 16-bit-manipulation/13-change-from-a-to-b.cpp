/*******************************************************************
 * NUMBER OF BITS TO CHANGE a => b
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count_1s(int num) {
    int ctr = 0;
    while(num != 0) {
        ctr++;
        num = num & (num - 1);
    }
    return ctr;
}

// find the number of bits to change from number "a" to number "b"
/*
    a = 10110 (22)
    b = 11011 (27)
*/
int change(int a, int b) {
    
    // XOR operation
    int x = a ^ b;

    // Count number of 1's in XOR result x
    int ans = count_1s(x);

    return ans;
}

int main() {

    cout<<change(22, 27);
    return 0;
}
