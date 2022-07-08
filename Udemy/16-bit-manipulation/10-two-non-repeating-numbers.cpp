/*******************************************************************
 * TWO NON REPEATING NUMBERS
 * 
 * Find the two non-repeating elements in an array where every 
 * element repeats twice.
*******************************************************************/
#include<bits/stdc++.h>
using namespace std;

pair<int, int> two_non_repeating(vector<int> arr) {

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

    return {x, y};
}


int main() {

    vector<int> arr = {1, 10, 6, 6, 3, 8, 9, 10, 9, 8, 1, 5}; // 3, 5

    auto p = two_non_repeating(arr);
    cout<<p.first<<", "<<p.second;
    return 0;
}