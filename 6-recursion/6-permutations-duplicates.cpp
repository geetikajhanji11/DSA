/**************************************************************

https://www.youtube.com/watch?v=qhBVWf0YafA&ab_channel=NeetCode

DUPLICATE PERMUTATIONS

Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

Example 1:
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
    Input: nums = [1,1,2]
    Output:
        [[1,1,2],
        [1,2,1],
        [2,1,1]]

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

void recur(vector<vector<int>> &result, vector<int> nums, vector<int> curr, unordered_map<int, int> mp) {

    // base case
    if(curr.size() == nums.size()) {
        result.push_back(curr);
        return;
    }

    // recursive case
    for(auto x : mp) {
        int num = x.first;
        int freq = x.second;
        if(freq != 0) {
            mp[num] -= 1;
            curr.push_back(num);
            recur(result, nums, curr, mp);
            curr.pop_back();
            mp[num] += 1;
        }
    }
    
}

vector<vector<int>> permutations(vector<int> nums) {
    vector<vector<int>> result;
    vector<int> curr;

    unordered_map<int, int> mp;
    for(int num : nums) {
        mp[num]++;
    }

    recur(result, nums, curr, mp);

    return result;
    
}

// main function 
int main() {
    
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = permutations(nums);
    for(vector<int> res : result) {
        for(int num : res) {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}