/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********** APPROACH - 1 ********** 
// O(26) + O(N)
bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;

    vector<int> s1_map(26, 0);
    vector<int> window_map(26, 0);

    // fill up s1_map
    for(char ch : s1) {
        s1_map[ch - 'a']++;
    }

    // fill up window_map
    int left = 0;
    int right = s1.length() - 1;
    for(int i=left; i<=right; i++) {
        window_map[s2[i] - 'a']++;
    }    

    // calculate initial matches O(26)
    int matches = 0;
    for(int i=0; i<26; i++) {
        if(s1_map[i] == window_map[i]) {
            matches++;
        }
    }

    while(right < s2.length()) {
        if(matches == 26) return true;

        // remove s2[left]
        int left_index = s2[left] - 'a';
        window_map[left_index]--;
        if(s1_map[left_index] == window_map[left_index]) 
            matches++;
        else if(s1_map[left_index] - 1 == window_map[left_index])
            matches--;

        left++;

        // add s2[right]
        right++;
        if(right == s2.length()) break;
        int right_index = s2[right] - 'a';
        window_map[right_index]++;
        if(s1_map[right_index] == window_map[right_index]) 
            matches++;
        else if(s1_map[right_index] + 1 == window_map[right_index]) 
            matches--;
    }

    return false;
}


// ********** APPROACH - 2 ********** 
// O(26*N)
bool is_permutation(unordered_map<char, int> &s1_map, unordered_map<char, int> &window_map) {
    for(auto itr=s1_map.begin(); itr!=s1_map.end(); itr++) {
        char key = itr->first;
        int value = itr->second;
        if(window_map.find(key) == window_map.end()) return false;
        if(window_map[key] != value) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {

    if(s1.length() > s2.length()) return false;

    unordered_map<char, int> s1_map;
    for(char ch : s1) s1_map[ch]++;

    // build initial window
    unordered_map<char, int> window_map;
    int left = 0;
    int right = s1.length() - 1;
    for(int i=left; i<=right; i++) {
        window_map[s2[i]]++;
    }

    while(right < s2.length()) {
        if(is_permutation(s1_map, window_map)) return true;

        // deleting left char from window
        window_map[s2[left]]--;
        if(window_map[s2[left]] == 0) window_map.erase(s2[left]);
        left++;

        // including right char in window
        right++;
        if(right == s2.length()) break;
        window_map[s2[right]]++;
    }

    return false;
}

int main() {

    return 0;
}