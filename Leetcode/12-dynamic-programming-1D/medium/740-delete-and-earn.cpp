/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// *************** DP ***************
class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums) count[num]++;

        vector<int> uniqueNums;
        for(auto kv : count) {
            uniqueNums.push_back(kv.first);
        }
        sort(uniqueNums.begin(), uniqueNums.end());

        // e1, e2, i
        // [1,  2, 3]
        int earn1 = 0;
        int earn2 = 0;
        for(int i=0; i<uniqueNums.size(); i++) {
            int currEarn = uniqueNums[i] * count[uniqueNums[i]];

            if(i-1 >= 0 && uniqueNums[i] - 1 == uniqueNums[i - 1]) {
                int tempEarn2 = earn2;
                earn2 = max(currEarn + earn1, earn2);
                earn1 = tempEarn2;
            } else {
                int tempEarn2 = earn2;
                earn2 = currEarn + earn2;
                earn1 = tempEarn2;
            }
        }

        return earn2;
    }
};

// *************** RECURSIVE SOLUTION ***************
// USING MAP
class Solution {
public:

    int earnMax(unordered_map<int, int> count) {

        if(count.size() == 0) return 0;

        int ans = 0;
        for(auto kv_pair : count) {

            int num = kv_pair.first;
            int freq = kv_pair.second;

            if(freq <= 0) continue;

            // choosing num in ans
            // delete all num-1 and num+1
            // delete one occurence of num

            int leftFreq = 0;
            if(count.find(num-1) != count.end()) {
                leftFreq = count[num-1];
                count[num-1] = 0;
            }

            int rightFreq = 0;
            if(count.find(num+1) != count.end()) {
                rightFreq = count[num+1];
                count[num+1] = 0;
            }

            count[num] -= 1;

            // dfs call
            int remainingProfit = earnMax(count);
            ans = max(ans, remainingProfit + num);
            
            // backtrack
            if(leftFreq != 0) count[num-1] = leftFreq;
            if(rightFreq != 0) count[num+1] = rightFreq;
            count[num]+= 1;

        }

        return ans;
    
    }

    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int, int> count;
        for(int num : nums) count[num]++;

        return earnMax(count);

    }
};


// *************** RECURSIVE SOLUTION ***************
// USING VECTOR
class Solution {
public:

    int earnMax(int i, vector<int> nums) {

        if(i == nums.size()) return 0;

        int ans = 0;
        for(int j=i; j<nums.size(); j++) {
            // choosing nums[j]
            // delete all nums[j]-1 and nums[j]+1
            // delete one occurence of nums[j]
            vector<int> temp;
            int deleted = false;
            for(int num : nums) {
                if(num == nums[j]-1 || num == nums[j]+1) continue;
                if(!deleted && num == nums[j]) {
                    deleted = true;
                    continue;
                }
                temp.push_back(num);
            }
            
            int remProfit = earnMax(0, temp);
            ans = max(ans, remProfit + nums[j]);
        }

        return ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        return earnMax(0, nums);
    }
};