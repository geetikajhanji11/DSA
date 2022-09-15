/*******************************************************************
https://www.youtube.com/watch?v=JT1NDR-M_8A&ab_channel=TECHDOSE

EXAMPLE : "LEETCODE"

L : [0]
    (0,0) and (0,7)
      1    *    8       => 8

E : [1,2,7]
    (0,1) and (1,1)
      2    *    1       => 2
    (2,2) and (2,6)
      1    *    5       => 5
    (3,7) and (7,7)
      5    *    1       => 5

T : [3]
    (0,3) and (3,7)
      4    *    5       => 20

C : [4]
    (0,4) and (4,7)
      5    *    4       => 20

O : [5]
    (0,5) and (5,7)
      6    *    3       => 18

D : [6]
    (0,6) and (6,7)
      7    *    2       => 14

Total   =   (8) + (2 + 5 + 5) + (20) + (20) + (18) + (14) 
        =   92
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** COUNT CONTRIBUTIONS ***********
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> occurenceIdx;

        for(int i=0; i<s.length(); i++) {
            occurenceIdx[s[i]].push_back(i);
        }

        int left = 0;
        int right = s.length() - 1;

        int result = 0;

        for(auto kv : occurenceIdx) {
            char ch = kv.first;
            vector<int> indexes = kv.second;

            int leftIdx = 0;

            for(int i=0; i<indexes.size(); i++) {
                int rightIdx = i+1 < indexes.size() ? indexes[i+1] - 1 : s.length() - 1;
                int middleIdx = indexes[i];

                int leftElements = middleIdx - leftIdx + 1;
                int rightElements = rightIdx - middleIdx + 1;

                int contributions = leftElements * rightElements;
                result += contributions;

                leftIdx = middleIdx + 1;
            }
            
        }

        return result;
    }
};

// *********** BRUTE FORCE NAIVE ***********
// O(N^2)
class Solution {
public:
    int uniqueLetterString(string s) {
        int count = 0;

        for(int i=0; i<s.length(); i++) {

            vector<int> freq(26, 0);
            vector<bool> seen(26, false);
            int wordLength = 0;

            for(int j=i; j<s.length(); j++) {
                int idx = tolower(s[j]) - 'a';

                freq[idx]++;
                wordLength++;

                if(freq[idx] == 1 && !seen[idx]) {
                    seen[idx] = true;
                } else {
                    wordLength -= freq[idx];
                    freq[idx] = 0;
                }
                count += wordLength;
            }
        }

        return count;
    }
};