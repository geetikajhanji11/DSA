/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* BUCKET SORT SOLUTION *************

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        vector<vector<char>> bucket(n+1);

        unordered_map<char, int> freq;
        for(char ch : s) freq[ch]++;

        for(auto kv : freq) {
           bucket[kv.second].push_back(kv.first);
        }

        string result = "";
        for(int frequency=bucket.size()-1; frequency>=0; frequency--) {
            if(bucket[frequency].size() == 0) continue;
            for(char ch : bucket[frequency]) {
                string currString(frequency, ch);
                result += currString;
            }
        }

        return result;
    }
};


// ************* HEAP / SORTING SOLUTION *************
class Element {
public:
    char ch;
    int freq;
    Element(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
    }
};

class Compare {
public:
    bool operator()(Element e1, Element e2) {
        return e1.freq < e2.freq;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for(char ch : s) freq[ch]++;
        
        priority_queue<Element, vector<Element>, Compare> maxHeap;
        
        for(auto kv : freq) {
            maxHeap.push(Element(kv.first, kv.second));
        }

        string result = "";
        while(!maxHeap.empty()) {
            string currString(maxHeap.top().freq, maxHeap.top().ch);
            result += currString;
            maxHeap.pop();
        }

        return result;
    }
};