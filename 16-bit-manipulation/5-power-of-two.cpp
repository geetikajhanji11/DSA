/*******************************************************************
 * CHECK IF NUMBER IS POWER OF TWO
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_power_of_two(int n) {
    if((n & (n-1)) == 0) return true;
    return false;
}

int main() {

    for(int i=0; i<=100; i++) {
        if(is_power_of_two(i)) {
            cout<<i<<" is power of 2\n";
        }
    }
    return 0;
}