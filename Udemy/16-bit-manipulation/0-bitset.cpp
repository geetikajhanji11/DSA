/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void binary(int num){
    //converts the number to binary
    //and removes leading zeroes
    cout << bitset<32>(num).to_string().substr(32 - log2(num));
}

int main() {

    return 0;
}