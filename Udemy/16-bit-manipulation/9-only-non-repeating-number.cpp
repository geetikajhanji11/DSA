/*******************************************************************
 * ONLY NON REPEATING NUMBER
 * 
 * Find the only non-repeating element in an array where every 
 * element repeats twice
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int only_non_repeating(vector<int> arr) {
    int ans = 0;
    for(int num : arr) {
        ans = ans ^ num;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 10, 6, 6, 3, 8, 9, 10, 9, 8, 1};  // 3
    cout<<only_non_repeating(arr);
    return 0;
}