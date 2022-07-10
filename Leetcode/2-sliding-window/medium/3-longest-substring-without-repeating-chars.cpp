/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    if(n == 0) return 0;

    int left = 0;
    int right = 0;

    unordered_set<char> hashSet;
    int longest_length = 1;

    while(right < n) {
        char ch = s[right];
        if(hashSet.find(ch) != hashSet.end()) {
            while(s[left] != ch) {
                hashSet.erase(hashSet.find(s[left]));
                left++;
            }
            hashSet.erase(hashSet.find(s[left]));
            left++;
        }
        hashSet.insert(ch);
        longest_length = max(longest_length, right-left+1);

        right++;
    }   

    return longest_length;
}

int main() {

    string s = "bbbbb";
    cout<<lengthOfLongestSubstring(s);

    return 0;
}