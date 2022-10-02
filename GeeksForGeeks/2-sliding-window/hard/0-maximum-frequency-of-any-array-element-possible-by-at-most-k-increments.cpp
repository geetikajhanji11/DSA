/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &arr, int k) {

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = 0;

    int subarraySum = 0;
    int maxFreq = 0;

    while(right < arr.size()) {

        // keep track of current subarray sum
        subarraySum += arr[right];

        // contract window
        // keep decreasing the window until a valid window is formed
        while((right - left + 1) * arr[right] - subarraySum > k) {
            subarraySum -= arr[left];
            left++;
        }

        // valid window
        maxFreq = max(maxFreq, right - left + 1);

        // expand window
        right++;
    }

    return maxFreq;
}

int main() {

    vector<int> arr1 = {1,4,8,13};
    int k1 = 5;

    vector<int> arr2 = {2,4,5};
    int k2 = 4;

    cout<<maxFrequency(arr1, k1)<<endl;
    cout<<maxFrequency(arr2, k2)<<endl;

    return 0;
}