/*******************************************************************
 * DECIMAL TO BINARY
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

// *************** METHOD-1 ***************
string decimal_to_binary(int n) {

    // Size of an integer is assumed to be 32 bits
    string binary = "";
    for (int i = 31; i >= 0; i--) {
        int bit = n >> i;
        if (bit & 1) binary += '1';
        else binary += '0';
    }

    int start = 0;
    while(binary[start] != '1') start++;
    binary = binary.substr(start, binary.length() - start);

    return binary;
}

// *************** METHOD-2 ***************
int decimalToBinary(int N)
{
    // To store the binary number
    ull B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        // Count used to store exponent value
        cnt++;
    }
    return B_Number;
}

int main() {

    int n = 10;
    cout<<decimal_to_binary(n)<<endl;
    cout<<decimalToBinary(n)<<endl;
    
    return 0;
}