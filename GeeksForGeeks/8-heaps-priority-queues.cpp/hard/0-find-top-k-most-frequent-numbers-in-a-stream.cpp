/*******************************************************************
TEST CASES
{5, 2, 1, 3, 2};
{5, 2, 1, 3, 4}; 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> topKFrequent(vector<int> nums, int k) {

    // 0 to indicate empty spot
    vector<int> topK(k+1, 0);

    // stores frequency of each number
    unordered_map<int, int> freq;

    // for every number in data stream
    vector<vector<int>> result;
    for(int num : nums) {
        freq[num]++;

        topK[k] = num;

        // search if number exists already
        // in the top k array, if it does,
        // remember its position
        int pos = k;
        for(int i=0; i<k; i++) {
            if(topK[i] == num) {
                pos = i;
                break;
            }
        }

        // iterate from the position of element to zero
        for(int i=pos-1; i>=0; i--) {
            if(freq[topK[i]] < freq[topK[i+1]]) {
                swap(topK[i], topK[i+1]);
            } else if(freq[topK[i]] == freq[topK[i+1]] && topK[i] > topK[i+1]) {
                swap(topK[i], topK[i+1]);
            } else break;
        }

        // add topK array in result
        // ignore '0' entries
        vector<int> intermediateResult;
        for(int i=0; i<k; i++) {
            if(topK[i] == 0) continue;
            intermediateResult.push_back(topK[i]);
        }

        result.push_back(intermediateResult);
    }

    return result;
}

int main() {

    vector<int> nums = {5, 2, 1, 3, 4}; 
    int k = 4;
    auto ans = topKFrequent(nums, k);

    for(auto topkArray : ans) {
        for(int num : topkArray) {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}