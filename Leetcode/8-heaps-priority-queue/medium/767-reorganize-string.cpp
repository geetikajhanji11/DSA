/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Character {
public:
    char ch;
    int freq;
    Character() {}
    Character(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
    }
};

class Compare {
public:
    bool operator()(Character c1, Character c2) {
        return c1.freq < c2.freq;
    }
};

class Solution {

public:
    string reorganizeString(string s) {

        // count frequency of each character
        vector<int> frequency(26, 0);
        for(char ch : s) {
            frequency[ch-'a']++;
        }

        // push all the characters into a max heap
        // heap sorted according to frequency of character
        priority_queue<Character, vector<Character>, Compare> maxHeap;
        for(int i=0; i<frequency.size(); i++) {
            char ch = 'a' + i;
            int freq = frequency[i];
            if(freq > 0) {
                Character c(ch, freq);
                maxHeap.push(c);
            }
        }

        // higher frequency character 
        // which is NOT equal to last character
        // is added to result first
        string result = "";
        char lastChar = ' ';
        while(!maxHeap.empty()) {
            
            Character curr;

            // current character is not equal to last character
            if(maxHeap.top().ch != lastChar) {
                curr = maxHeap.top(); maxHeap.pop();
            } 
            
            // current character is equal to last character
            else {

                // get the same character
                Character sameChar = maxHeap.top(); maxHeap.pop();
                
                // if now heap is empty (no unique character 
                // after this exists), return ""
                if(maxHeap.empty()) return "";

                // other unique characters exist,
                // get that next unique character, then
                // push the same character back to heap
                curr = maxHeap.top(); maxHeap.pop();
                maxHeap.push(sameChar);
            }

            result += curr.ch;
            curr.freq = curr.freq - 1;
            if(curr.freq > 0) { // still some instances of this ch are left
                maxHeap.push(curr);
            }
            
            // reset last character
            lastChar = curr.ch;

        }

        return result;
    }
};