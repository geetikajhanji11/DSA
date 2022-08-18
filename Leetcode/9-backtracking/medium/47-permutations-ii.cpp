/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permutations(vector<int> curr, int n, unordered_map<int, int> m, vector<vector<int>> &result) {

    // permuation finished
    // add to result
    if(curr.size() == n) {
        result.push_back(curr);
        return;
    }

    // for each unique number in map
    for(auto element : m) {
        int num = element.first;
        int count = element.second;
        if(count == 0) continue;

        curr.push_back(num);
        m[num]--;
        permutations(curr, n, m, result);
        m[num]++;
        curr.pop_back();
    }
    
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int, int> m;
    for(int num : nums) m[num]++;
    vector<vector<int>> result;

    permutations({}, nums.size(), m, result);

    return result;
}

int main() {

    return 0;
}