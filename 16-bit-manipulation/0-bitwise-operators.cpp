/*******************************************************************
 * BINARY OPERATORS

&   =>  Binary AND
|   =>  Binary OR
^   =>  Binary XOR 
~   =>  Binary One's Complement
<<  =>  Binary Left Shift
>>  =>  Binary Right Shift

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int a = 5;
    int b = 7;

    int answer = a & b;
    cout<<"\nAND = "<<answer;

    answer = a | b;
    cout<<"\nOR = "<<answer;

    answer = a ^ b;
    cout<<"\nXOR = "<<answer;

    answer = ~a;
    cout<<"\nNOT = "<<answer;

    // a<<b == a * 2^b
    answer = a<<b; // 5 * 2^7 = 5 * 128 = 640
    cout<<"\nLeft Shift = "<<answer;

    // a>>b = a / 2^b 
    answer = a>>1; // 5 / 2 = 2.5 = 2 (integer division)
    cout<<"\nRight Shift = "<<answer;

    return 0;
}