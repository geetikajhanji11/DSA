/*******************************************************************
Find out the longest length of subarrays with at most 2 different numbers?
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// k = 2
// ********** generalizing **************
class Solution {
public:
    int totalFruit(vector<int> &tree) {

        unordered_map<int, int> count;
        int i = 0;
        int j = 0;
        int maxFruits = 0;
        for (j=0; j<tree.size(); j++) {
            count[tree[j]]++;
            while (count.size() > 2) {
                count[tree[i]]--;
                if(count[tree[i]] == 0) {
                    count.erase(tree[i]);
                }
                i++;
            }
            maxFruits = max(maxFruits, j - i + 1);
        }

        // window size
        return maxFruits;
    }
};