/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> unique;

        for(int num : nums1) {
            unique.insert(num);
        }

        vector<int> result;
        for(int num : nums2) {
            if(unique.find(num) != unique.end()) {
                result.push_back(num);
                unique.erase(num);
            }
        }

        return result;
    }
};