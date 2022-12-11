/*******************************************************************
O(NlogK)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string p, vector<bool> &removed) {
    int i = 0;
    int j = 0;
    while(i < s.length() && j < p.length()) {
        if(removed[i] || s[i] != p[j]) {
            i++;
            continue;
        }
        i++;
        j++;
    }
    return j == p.length();
}

int maximumRemovals(string s, string p, vector<int>& removable) {

    int low = 0;
    int high = removable.size() - 1;

    int result = 0;
    while(low <= high) {
        int mid = (low + high) / 2;

        vector<bool> removed(s.length(), false);
        for(int i=0; i<=mid; i++) {
            removed[removable[i]] = true;
        }

        if(isSubsequence(s, p, removed)) {
            result = max(result, mid + 1);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {

    return 0;
}