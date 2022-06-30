// https://www.youtube.com/watch?v=bTauscvOymA&list=PLUcsbZa0qzu3yNzzAxgvSgRobdUUJvz7p&index=4&ab_channel=AnujBhaiya

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// **************** SHIFT OPERATION ********************* //
void shift_operation(int n) {

    // whenever we right shift a number by 1,
    // we basically divide that number by 2 (floor division)
    int num = n;
    cout<<"\nRIGHT SHIFT BY 1 (DIV BY 2)\n";
    while(num != 0) {
        cout<<num<<", ";
        num = num>>1;
    }

    // whenever we left shift a number by 1,
    // we basically multiply that number by 2 
    num = n;
    cout<<"\n\nLEFT SHIFT BY 1 (MUL BY 2)\n";
    while(num <= 500) {
        cout<<num<<", ";
        num = num<<1;
    }
}

// ********************* ODD OR EVEN********************** //
void odd_or_even(int num) {
    cout<<"\n\nODD OR EVEN\n";
    int bit = num & 1;
    if(bit == 0) cout<<num<<" is Even.";
    else cout<<num<<" is Odd.";
}

// ************************ SWAP ********************* //
void swap(int a, int b) {
    cout<<"\n\nSWAP\n";
    cout<<"a = "<<a<<", b = "<<b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"\na = "<<a<<", b = "<<b;
}

// ************** FIND ITH BIT ****************** //
int find_ith_bit(int num, int i) {

    // move the position of the bits 5 positions to the left side 
    // and add zeroes to the empty space created at the  right side 
    // after shifting the bits.
    /*
        ----- i = 5 -----
        309     => 100110101
        mask    => 000100000 (1 is at 5th position)
    */
    int mask = 1<<i; 
    int arbitary = num & mask; // 32 (000100000)

    if(arbitary != 0) return 1;
    else return 0;
    
}

// ************** SET ITH BIT ****************** //
// make 0 => 1
void set_ith_bit(int num, int i) {
    /*
        ----- i = 7 -----
        309     => 100110101
        mask    => 010000000 (1 is at 7th position)
    */
    int mask = 1<<i;
    int ans = num | mask; // 110110101 (437)
    cout<<"\n\tAfter setting "<<i<<"th bit = "<<ans;
}

// ************** RESET ITH BIT ****************** //
// make 1 => 0
void reset_ith_bit(int num, int i) {
    /*
        ----- i = 4 -----
        309     =>   100110101
        mask    => ~(000010000) (1 is at 4th position)
                =>   111101111
    */
   int mask = ~(1<<i);
   int ans = num & mask;
   cout<<"\n\tAfter resetting "<<i<<"th bit = "<<ans;
}

// ************** NUMBER OF BITS TO CHANGE a => b ****************** //
int count_1s(int num) {
    int ctr = 0;
    while(num != 0) {
        ctr++;
        num = num & (num - 1);
    }
    return ctr;
}

// find the number of bits to change from number "a" to number "b"
int change(int a, int b) {
    /*
        a = 10110 (22)
        b = 11011 (27)
    */

    // XOR operation
    int x = a ^ b;

    // Count number of 1's in XOR result x
    int ans = count_1s(x);

    cout<<"\nNumber of bits different = "<<ans;
    return ans;
}

// ****************** Q1 ****************** //
/*
    Find the only non-repeating element in an 
    array where every element repeats twice
*/
void only_non_repeating() {
    vector<int> arr = {1, 10, 6, 6, 3, 8, 9, 10, 9, 8, 1}; // 3
    int ans = 0;
    for(int num : arr) {
        ans = ans ^ num;
    }
    cout<<"\n\nQ1. Only non-repeating element in an array where every element repeats twice = "<<ans;
}

// ****************** Q2 ****************** //
/*
    Find the two non-repeating elements in an
    array where every element repeats twice
*/
void two_non_repeating() {
    vector<int> arr = {1, 10, 6, 6, 3, 8, 9, 10, 9, 8, 1, 5}; // 3, 5
    int result = 0;
    for(int num : arr) {
        result = result ^ num;
    }

    /* 3 ^ 5*/
    int x_xor_y = result; 

    /* Get the rightmost set bit in set_bit_no */
    int set_bit_no = result & ~(result - 1);

    /* Now divide elements in two sets by
    comparing rightmost set bit of result with bit
    at same position in each element. */
    for (int num : arr) {

        // all those numbers whose rightmost bit position is set (1)
        // is kept in a group. This group contains x only or y only.
        if((num & set_bit_no) == set_bit_no) {
            result = result ^ num;
        }
    }

    int x = result;
    int y = x_xor_y ^ x;

    cout<<"\n\nQ2. Two non-repeating elements in an array where every element repeats twice = "<<x<<", "<<y;
}

// ****************** Q3 ****************** //
/*
    Find the only non-repeating element in an
    array where every other element repeats
    thrice
*/
void only_non_repeating_three() {
    vector<int> arr = {1, 2, 6, 7, 6, 2, 1, 6, 1, 2}; // 7
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
    cout<<"\n\nOnly non-repeating element in an array where every other element repeats thrice = "<<result;
}

// ********************* MAIN *********************** //
int main() {

    shift_operation(25);

    odd_or_even(25);

    swap(3, 7);

    cout<<"\n\n 309 => 100110101\n";
    int bit = find_ith_bit(309, 5);
    cout<<"\t5th bit = "<<bit;
    set_ith_bit(309, 7);
    reset_ith_bit(309, 4);

    change(22, 27);

    // Q1
    only_non_repeating();

    // Q2
    two_non_repeating();

    // Q3
    only_non_repeating_three();

    return 0;
}