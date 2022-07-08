/******************************************************************************

GROUP ANAGRAMS

Given a vector of strings, your task is to group the anagram together.
An Anagram is a words or phrase formed by reaaranging the letters 
of a different word or phrase, typically using all the original letters
exactly once.

Input: 
    words = {
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat",
    };
    
Output: 
    [
        ["bat"],
        ["nat", "tan"],
        ["ate", "eat", "tea"]
    ]
    
*******************************************************************************/
#include<iostream>
#include<map>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string> strs) {
    
    map< vector<int>, vector<string> > mp;
    
    for(string word : strs) {
        vector<int> freq(26, 0);
        for(char ch : word) {
            freq[ch - 'a']++;
        }
        
        if(mp.find(freq) != mp.end()) {
            mp[freq].push_back(word);
        } else {
            vector<string> anagrams;
            anagrams.push_back(word);
            mp[freq] = anagrams;
        }
        
    }
    
    vector<vector<string>> wordAnagrams;
    for(auto &it: mp) {
        vector<string> anagrams;
        for(string anagram : it.second) {
            anagrams.push_back(anagram);
        }
        wordAnagrams.push_back(anagrams);
    }
    
    return wordAnagrams;
    
}

int main() {
    
    vector<string> strs{
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat",
    };
    
    vector<vector<string>> result = groupAnagrams(strs);
    cout<<"\nRESULT\n";
    for(vector<string> words : result) {
        for(string word : words) {
            cout<<word<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
