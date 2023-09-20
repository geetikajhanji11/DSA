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

// *********** UNORDERED MAP ***********
class Solution {

    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }

public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
    
};

// *********** ORDERED MAP ***********
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;

        for(string str : strs) {
            vector<int> count(26, 0);
            for(char c : str) count[c - 'a']++;
            m[count].push_back(str);
        }

        vector<vector<string>> result;
        for(auto itr : m) {
            result.push_back(itr.second);
        }

        return result;
    }
};