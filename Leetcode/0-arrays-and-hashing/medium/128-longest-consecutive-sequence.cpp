/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    
    unordered_set<int> s;
    unordered_map<int, int> m;
    for(int num : nums) {
        s.insert(num);
    }

    int longest_length = 0;
    for(auto it=s.begin(); it!=s.end(); it++) {
        int num = *it;
        int prev = num - 1;
        int ctr = 0;
        int remaining = 0;
        while(s.find(prev) != s.end()) {
            if(m.find(prev) != m.end()) {
                remaining = m[prev];
                break;
            }
            ctr++;
            prev = prev - 1;
        }
        m[num] = ctr + remaining + 1;
        longest_length = max(longest_length, m[num]);
    }

    return longest_length;
}

int main() {

    vector<int> nums1 = {0,3,7,2,5,8,4,6,0,1};
    vector<int> nums2 = {100,4,200,1,3,2};
    cout<<longestConsecutive(nums1)<<endl;
    cout<<longestConsecutive(nums2)<<endl;
    return 0;
}