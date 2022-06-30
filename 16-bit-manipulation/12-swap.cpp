/*******************************************************************
 * SWAP TWO NUMEBRS
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int a, int b) {
    cout<<"a = "<<a<<", b = "<<b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"\na = "<<a<<", b = "<<b;
}

int main() {

    swap(3, 9);
    return 0;
}