/*******************************************************************
 * ODD OR EVEN
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void odd_or_even(int num) {
    int bit = num & 1; // LSB 
    if(bit == 0) cout<<num<<" is Even.\n";
    else cout<<num<<" is Odd.\n";
}

int main() {

    odd_or_even(6);
    odd_or_even(7);
    return 0;
}