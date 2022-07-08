/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for(int num : nums) {
        m[num]++;
    }

    vector<vector<int>> count(nums.size()+1, vector<int>());
    for(auto it=m.begin(); it!=m.end(); it++) {
        int num = it->first;
        int freq = it->second;
        count[freq].push_back(num);
    }

    vector<int> result;
    for(int i=count.size()-1; i>=0; i--) {
        int n = count[i].size();
        if(n != 0) {
            for(int j=0; j<n; j++) {
                result.push_back(count[i][j]);
                k--;
                if(k == 0) return result;
            }
        }
    }

    return result;
}

int main() {

    return 0;
}