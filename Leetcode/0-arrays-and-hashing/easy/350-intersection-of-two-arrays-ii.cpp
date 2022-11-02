/*******************************************************************
Follow-up Question 3: What if elements of nums2 are stored on disk, 
and the memory is limited such that you cannot load all elements 
into the memory at once?

If nums1 fits into the memory, we can use Approach 1 which stores 
all elements of nums1 in the HashMap. Then, we can sequentially load 
and process nums2.

If neither nums1 nor nums2 fits into the memory, we split the numeric 
range into numeric sub-ranges that fit into the memory.

We modify Approach 1 to count only elements which belong to the 
given numeric sub-range.
We process each numeric sub-ranges one by one, util we process all 
numeric sub-ranges.

For example:
Input constraint:
1 <= nums1.length, nums2.length <= 10^10.
0 <= nums1[i], nums2[i] < 10^5
Our memory can store up to 1000 elements.
Then we split numeric range into numeric sub-ranges 
[0...999], [1000...1999], ..., [99000...99999], 
then call Approach 1 to process 100 numeric sub-ranges.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(n) space 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> count;

        for(int num : nums1) count[num]++;

        vector<int> result;
       
        for(int num : nums2) {
            if(count.find(num) != count.end() && count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        return result;
    }
};

// O(nlogn) time
// O(1) space 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        vector<int> result;
        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            } 

            else if(nums1[i] < nums2[j]) i++;

            else j++;
        }

        return result;
    }
};