/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<string, int>>> m;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = m[key].size() - 1;

        string result = "";
        while(low <= high) {
            int mid = (low + high) / 2;

            if(m[key][mid].second == timestamp) return m[key][mid].first;

            if(m[key][mid].second < timestamp) {
                result = m[key][mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};