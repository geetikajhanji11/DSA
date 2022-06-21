/*******************************************************************
 * LONGEST INCREASING SUBSEQUENCE
 * 
 * Given an array sequence, find the length of the longest 
 * subsequence of such that all the elements of the subsequence 
 * are sorted in increasing order.
 * 
 * INPUT
 *      arr = {50, 4, 10, 8, 30, 100}
 * 
 * OUTPUT
 *      4 {4, 8, 30, 100}
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longest_increasing_subsequence(vector<int> arr) {
    vector<int> dp(arr.size(), 1);
    dp[0] = 1;
    int max_len = 1;

    for(int i=1; i<arr.size(); i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], 1+dp[j]);
                max_len = max(max_len, dp[i]);
            }   
        }
    }

    return max_len;
}

int main() {

    vector<int> arr = {50, 4, 10, 8, 30, 100};
    cout<<longest_increasing_subsequence(arr);
    return 0;
}