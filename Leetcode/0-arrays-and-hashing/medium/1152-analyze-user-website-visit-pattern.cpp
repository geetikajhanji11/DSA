/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Visit {
public:
    string username;
    int timestamp;
    string website;
    Visit(string username, int timestamp, string website) {
        this->username = username;
        this->timestamp = timestamp;
        this->website = website;
    }
};

bool customVisitSort(Visit v1, Visit v2) {
    return v1.timestamp < v2.timestamp;
}

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string> username, vector<int> timestamp, vector<string> website) {
        int n = username.size();
        
        // create class Visit for each entry
        vector<Visit> visitHistory;
        for(int i=0; i<n; i++) {
            Visit currVisit(username[i], timestamp[i], website[i]);
            visitHistory.push_back(currVisit);
        }

        // sorting according to timestamp
        sort(visitHistory.begin(), visitHistory.end(), customVisitSort);

        // store chronological website information for each user in map
        unordered_map<string, vector<string>> websitesVisitedBy;
        for(Visit v : visitHistory) {
            websitesVisitedBy[v.username].push_back(v.website);
            
        }

        // make combinations for each user
        map<vector<string>, int> threeSequence;
        int maxVisits = 0;
        for(auto kv : websitesVisitedBy) {
            string user = kv.first;
            vector<string> webs = kv.second;
            int m = webs.size();
            for(int i=0; i<m-2; i++) {
                for(int j=i+1; j<m-1; j++) {
                    for(int k=j+1; k<m; k++) {
                        vector<string> seq = {webs[i], webs[j], webs[k]};
                        threeSequence[seq]++;
                        maxVisits = max(maxVisits, threeSequence[seq]);
                    }
                }
            }
        }

        // return the first vector that has "maxVisits" frequency
        for(auto kv : threeSequence) {
            if(kv.second == maxVisits) {
                return kv.first;
            }
        }

        return {};
    }
};

int main() {

    Solution s;
    vector<string> username = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int> timestamp = {1,2,3,4,5,6,7,8,9,10};
    vector<string> website = {"home","about","career","home","cart","maps","home","home","about","career"};

    vector<string> res = s.mostVisitedPattern(username, timestamp, website);

    cout<<"\nRESULT = ";
    cout<<res[0]<<", "<<res[1]<<", "<<res[2];

    return 0;
}