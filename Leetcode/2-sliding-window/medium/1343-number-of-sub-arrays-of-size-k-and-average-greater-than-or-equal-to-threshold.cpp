/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int subarraySum = 0;
        int start = 0;
        int end = 0;

        int result = 0;
        while(end < arr.size()) {
            subarraySum += arr[end];

            // check current window
            // then start new window 
            if(end - start + 1 == k) {
                int avg = subarraySum / k;
                if(avg >= threshold) result++;
                subarraySum -= arr[start];
                start++;
            }

            end++;
        }

        return result;

    }
};