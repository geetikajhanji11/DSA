/*******************************************************************
right and (right-1) are always going to be 
in range because in while loop, condition is
(left < right), 
suppose,     right = (left + 1)
then         (right - 1) = left
then doing & between the two is valid since they are in range

and if right == left, it will 
not go into the loop and hence return
left & right... which is what we want
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;

        // keep contracting the window from the right
        // and keep working your way down the range
        // till reach start (left)
        while(left < right) {
            right = right & (right - 1);
        }

        return left & right;
    }
};

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         if(left == 0) return 0;

//         int ans = left;
//         for(int i=left; i<=right; i++) {
//             ans = ans & i;
//             if(ans == 0) return 0;
//         }

//         return ans;
//     }
// };