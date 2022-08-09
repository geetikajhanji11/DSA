/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int to_digit(char ch) {
    int num = ch - '0';
    return num;
}

string addBinary(string a, string b) {

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    string result = "";
    while(i >= 0 && j >= 0) {
        int bit_a = to_digit(a[i]);
        int bit_b = to_digit(b[j]);
        int sum = bit_a + bit_b + carry;

        carry = sum / 2;
        sum = sum % 2;

        result += to_string(sum);
        
        i--;
        j--;
    }

    while(i >= 0) {
        int bit_a = to_digit(a[i]);
        int sum = bit_a + carry;
        carry = sum / 2;
        sum = sum % 2;
        result += to_string(sum);
        i--;
    }

    while(j >= 0) {
        int bit_b = to_digit(b[j]);
        int sum = bit_b + carry;
        carry = sum / 2;
        sum = sum % 2;
        result += to_string(sum);
        j--;
    }
    
    if(carry == 1) {
        result += '1';
    }

    reverse(result.begin(), result.end());
    return result;        
}

int main() {

    return 0;
}