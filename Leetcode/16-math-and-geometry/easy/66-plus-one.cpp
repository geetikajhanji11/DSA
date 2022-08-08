/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;

    int i = n - 1;
    while(i >= 0 && carry != 0) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] = digits[i] % 10;
        i--;
    }        

    if(i == -1 && carry == 1) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main() {

    return 0;
}