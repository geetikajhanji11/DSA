/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    
    int n = s.length();

    unordered_map<char, int> s_map;
    unordered_map<char, int> t_map;

    for(char ch : t) t_map[ch]++;

    int have = 0;
    int need = t_map.size();

    int start_index = -1;
    int min_length = INT_MAX;

    int left = 0;
    int right = 0;

    while(right < n) {

        char curr_ch = s[right];
        s_map[curr_ch]++;
        if(s_map[curr_ch] == t_map[curr_ch]) have++;
    
        // we found a valid substring
        if(have >= need) {
            int curr_length = right - left + 1;
            if(curr_length < min_length) {
                min_length = curr_length;
                start_index = left;
            }

            // removing the left elements
            // until we remove 1 element 
            // that makes the substring not valid
            while(have >= need) {
                char left_ch = s[left];
                s_map[left_ch]--;
                if(s_map[left_ch] < t_map[left_ch]) have--;
                left++;
            }

            // on removing the last left element,
            // we need to check if it had
            // the min length
            int temp_left = left - 1;
            int len = right - temp_left + 1;
            if(len < min_length) {
                min_length = len;
                start_index = temp_left;
            }
        } 
        right++;
    }

    if(start_index == -1) return "";

    string result = s.substr(start_index, min_length);
    return result;
}

int main() {

    string s = "ADOBECODEBANC", t = "ABC";
    cout<<minWindow(s, t);
    return 0;
}