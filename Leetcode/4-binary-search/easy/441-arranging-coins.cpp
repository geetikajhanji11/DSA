/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// **************** LINEAR **************** 
// int arrangeCoins(int n) {

//     int ans = 0;
//     int cumulative_sum = 0;
//     for(int i=1; ;i++) {
//         cumulative_sum += i;
//         if(cumulative_sum <= n) ans = i;
//         if(cumulative_sum > n) break;
//     }        
//     return ans;
// }

// **************** BINARY SEARCH ****************
// int arrangeCoins(int n) {

//     int low = 1;
//     int high = n;

//     int rows = 0;

//     while(low <= high) {
//         int mid = (low + high) / 2;
//         int mid_rows = mid % 2 == 0 ? (mid/2) * (mid+1) : mid * ((mid+1) / 2);
//         if(mid_rows <= n) {
//             rows = max(rows, mid);
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     return rows;
// }

// **************** MATHEMATICAL ****************
int arrangeCoins(int n) {
    return ((sqrt(1 + 8*n) - 1) / 2);
}

int main() {

    arrangeCoins(5);
    return 0;
}