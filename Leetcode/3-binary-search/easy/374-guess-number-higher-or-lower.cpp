/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    int guess(int num);
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int my_guess = guess(mid);
            if(my_guess == 0) return mid;
            else if(my_guess == -1) high = mid - 1;
            else low = mid + 1;
        }        
        return -1;
    }
};

int main() {

    return 0;
}