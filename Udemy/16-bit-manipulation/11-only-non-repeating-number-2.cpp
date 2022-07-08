/*******************************************************************
 * ONLY NON REPEATING NUMBER 2
 * 
 * Find the only non-repeating element in an array where every 
 * other element repeats thrice.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find_ith_bit(int num, int i) {
    int mask = 1<<i; 
    int arbitary = num & mask; // 32 (000100000)
    if(arbitary != 0) return 1;
    else return 0;
}

int only_non_repeating_three(vector<int> arr) {
    
    int SIZE = 32;
    int k = 3;
    vector<int> bits(SIZE, 0);

    // filling the bits array
    for(int num : arr) {
        for(int i=0; i<SIZE; i++) {
            int bit = find_ith_bit(num, i);
            if(bit == 1) {
                bits[i]++;
            }
        }
    }

    // converting binary to decimal
    int result = 0;
    for(int i=0; i<SIZE; i++) {
        if(bits[i] % k != 0)
            result += pow(2, i);
    }

    return result;
}

int main() {

    vector<int> arr = {1, 2, 6, 7, 6, 2, 1, 6, 1, 2}; // 7
    cout<<only_non_repeating_three(arr);
    return 0;
}