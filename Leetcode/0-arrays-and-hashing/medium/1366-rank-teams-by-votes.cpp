/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<char,vector<int>> a, pair<char, vector<int>> b) {
        int n = a.second.size();
        int i = 0;
        while(i < n && a.second[i] == b.second[i]) i++;
        if(i < n) return a.second[i] > b.second[i];
        return a.first < b.first;
    }

    string rankTeams(vector<string>& votes) {
        if(votes.size() == 1) return votes[0];

        int positions = votes[0].size();

        unordered_map<char, vector<int>> m;
        for(char cand : votes[0]) {
            m[cand] = {};
        }

        for(int pos=0; pos<positions; pos++) {

            unordered_map<char, int> curr_votes;
            for(int i=0; i<votes.size(); i++) {
                char cand = votes[i][pos];
                curr_votes[cand]++;
            }

            for(auto itr : m) {
                int cand = itr.first;
                if(curr_votes.find(cand) != curr_votes.end()) {
                    m[cand].push_back(curr_votes[cand]);
                } else {
                    m[cand].push_back(0);
                }
            }
        }

        vector<pair<char, vector<int>>> all_ranks;
        for(auto itr : m) {
            all_ranks.push_back({itr.first, itr.second});
        }   

        sort(all_ranks.begin(), all_ranks.end(), cmp);

        string result;
        for(auto p : all_ranks) {
            result.push_back(p.first);
        }

        return result;
    }
};

int main() {

    vector<string> votes = {"ABC","ACB","ABC","ACB","ACB"};
    Solution s;
    cout<<s.rankTeams(votes);

    return 0;
}