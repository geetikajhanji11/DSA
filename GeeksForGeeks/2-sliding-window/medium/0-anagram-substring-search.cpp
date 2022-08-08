/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> anagram_search(string s, string p) {

    vector<int> window_map(26, 0);
    vector<int> m(26, 0);

    for(char ch : p) {
        m[ch-'a']++;
    }

    int left = 0;
    int right = p.length()-1;
    for(int i=left; i<=right; i++) {
        window_map[s[i]-'a']++;
    }

    int matches = 0;
    for(int i=0; i<26; i++) {
        if(window_map[i] == m[i]) {
            matches++;
        }
    }

    
    vector<int> result;

    while(right < s.length()) {

        if(matches == 26) {
            result.push_back(left);
        }

        // remove the left element to window
        int l = s[left] - 'a';
        window_map[l]--;
        if(window_map[l] == m[l]) matches++;
        else if(window_map[l] + 1 == m[l]) matches--;
        left++;

        // add the right element to window
        right++;
        if(right >= s.length()) break;
        int r = s[right] - 'a';
        window_map[r]++;
        if(window_map[r] == m[r]) matches++;
        else if(window_map[r] - 1 == m[r]) matches--;
    }

    return result;

}

int main() {

    // string s = "bacdgabcda";
    // string p = "abcd";

    string s = "aaababaa";
    string p = "aaba";

    auto res = anagram_search(s, p);
    cout<<"here";
    cout<<res.size()<<endl;
    for(int index : res) cout<<index<<endl;

    return 0;
}