/*******************************************************************
Given 2 ints, return sum w/o using +/-
Ex. a = 1 b = 2 -> 3, a = 2 b = 3 -> 5

XOR for addition, AND for carry bit

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getSum(int a, int b) {
    while(b != 0) {
        int num1 = a ^ b;
        int num2 = (unsigned) (a & b) << 1;
        a = num1;
        b = num2;
    }      
    return a; 
}

int main() {

    return 0;
}