/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr) {

    unordered_map<int, int> m;
    for(int num : arr) m[num]++;

    vector<int> count;
    for(auto element : m) {
        count.push_back(element.second);
    }

    sort(count.begin(), count.end());

    int half = arr.size() / 2;
    int ctr = 0;

    for(int i=count.size()-1; i>=0; i--) {
        half = half - count[i];
        ctr++;
        if(half <= 0) break;
    }

    return ctr;
}

int main() {

    return 0;
}