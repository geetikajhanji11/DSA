/*******************************************************************
1.  Find the largest index j, such that the sub-array arr[i…j] is 
    non-decreasing. 
    This can be achieved by simply incrementing the value of j 
    starting from i + 1 and checking whether arr[j] is greater than arr[j – 1].

2.  Let’s say the length of the sub-array found in the previous step 
    is L. The number of sub-arrays of length K contained in it will be 
    max(L – K + 1, 0).

3.  Now, update i = j and repeat the above steps while i is in the 
    index range.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nonDecreasingSubarrays(vector<int> arr, int k) {
    int n = arr.size();
    int subarrays = 0;

    int i = 0;

    while(i < n) {

        int j = i + 1;

        // looping till the subarray is valid
        // i.e., non-decreasing
        while(j < n && arr[j-1] <= arr[j]) {
            j++;
        }

        // update count if subarray size >= k
        int L = j - i;
        subarrays += max(L - k + 1, 0);

        // update i
        i = j;
    }

    return subarrays;
}

int main() {

    return 0;
}