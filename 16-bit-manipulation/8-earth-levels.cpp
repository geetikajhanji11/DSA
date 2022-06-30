/*******************************************************************
 * EARTH LEVELS
 * 
 * The planet earth is under a threat from the aliens of the outer
 * space and your task is to defeat an enemy who is N steps above 
 * you (assume yourself at ground level i.e., 0th level). You
 * can take jumps in power of 2. In order to defeat the enemy as 
 * quickly as possible, you have to reach Nth step in minimum
 * moves possible.
 * 
 * Sample Input:
 *      7
 * 
 * Sample Output:
 *      3
 * 
 * Explanation:
 *      0 -> 4 -> 6 -> 7
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Since the jumps are required to be in perfect power of 2. 
// So the count of set bit in the given number N is the minimum 
// number of jumps required to reach Nth stair as the summation 
// of 2^i for all set bit index i is equals to N.
int earthLevel(int k) {
    int ctr = 0;
    while(k != 0) {
        ctr++;
        k = k & (k-1);
    }
    return ctr;
}

int main() {

    return 0;
}