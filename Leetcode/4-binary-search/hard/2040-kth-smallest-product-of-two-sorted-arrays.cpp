/*******************************************************************
https://www.youtube.com/watch?v=bZXt-mDqIZ0&ab_channel=Pepcoding
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    long long noOfElementsBeforeMid(vector<int>& nums1, vector<int>& nums2, long long &product) {
        long long count = 0;

        for(int num : nums1) {

            // for positive numbers
            if(num >= 0) {
                int low = 0;
                int high = nums2.size();
                while(low < high) {
                    int mid = (low + high) / 2;
                    if((long long) num * nums2[mid] < product) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }

                count += low;
            }

            // for negative numbers
            else {
                int low = 0;
                int high = nums2.size();
                while(low < high) {
                    int mid = (low + high) / 2;
                    if((long long) num * nums2[mid] >= product) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }

                count += nums2.size() - low;
            }
        }

        return count;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        long long min_nums1 = *min_element(nums1.begin(), nums1.end());
        long long max_nums1 = *max_element(nums1.begin(), nums1.end());

        long long min_nums2 = *min_element(nums2.begin(), nums2.end());
        long long max_nums2 = *max_element(nums2.begin(), nums2.end());

        vector<long long> v = {
            min_nums1 * min_nums2, 
            min_nums1 * max_nums2, 
            max_nums1 * min_nums2, 
            max_nums1 * max_nums2
        };

        long long low = LLONG_MAX;
        long long high = LLONG_MIN;

        for(long long prod : v) {
            low = min(low, prod);
            high = max(high, prod);
        }

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(noOfElementsBeforeMid(nums1, nums2, mid) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};