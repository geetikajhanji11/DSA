/*******************************************************************

LOGIC 1: (MINE)
Same as power of 2... but check for only "1" bit at even position.
if "1" bits are more than one, return false
if there is only "1" but in odd position return false

LOGIC 2: (DISCUSS)
we can turn every power of 4 within 32 bit into binary form, we will get:
1
100
10000
1000000
100000000
10000000000
1000000000000
100000000000000
10000000000000000
1000000000000000000
100000000000000000000
10000000000000000000000
1000000000000000000000000
100000000000000000000000000
10000000000000000000000000000
1000000000000000000000000000000
We XOR them together, we will get
1010101010101010101010101010101 (1431655765)

return n > 0 and not(n & (n - 1)) and n & 1431655765 == n
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* DISCUS SOLUTION ************* 
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        return !(n & (n - 1)) and (n & 1431655765) == n;
    }
};

// ************* MY SOLUTION ************* 
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        bool found_one = false;

        for(int i=0; i<32; i++) {

            int last_bit = n & 1;

            if(last_bit == 1) {

                // more than one "1" bits are there
                // in the binary representation of number
                if(found_one) return false;

                // found the first "1" bit at an even position
                else if(i % 2 == 0) found_one = true;

                // found the first "1" bit at an odd position
                else return false;
            }

            n = n>>1;

        }

        return found_one;
    }
};