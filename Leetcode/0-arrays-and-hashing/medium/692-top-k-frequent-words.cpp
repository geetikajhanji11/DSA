/*******************************************************************
https://www.youtube.com/watch?v=YPTqKIgVk-k&ab_channel=NeetCode
SIMILAR TO LEETCODE - 347 - TOP K FREQUENT ELEMENTS
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {

    int max_freq = words.size();
    vector<set<string>> freq(max_freq);

    unordered_map<string, int> m;
    for(string word : words) m[word]++;

    for(auto itr : m) {
        string word = itr.first;
        int count = itr.second;
        freq[count].insert(word);
    }

    vector<string> result;
    for(int i=freq.size()-1; i>=0; i--) {
        auto curr_set = freq[i];
        if(curr_set.size() == 0) continue;

        for(auto word : curr_set) {
            result.push_back(word);
            k--;
            if(k == 0) break;
        }
        if(k == 0) break;
    }

    return result;
}


int main() {

    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    auto ans = topKFrequent(words, k);
    for(auto a : ans) cout<<a<<endl;
    return 0;
}