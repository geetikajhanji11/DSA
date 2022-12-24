/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** DP SOLUTION **************
class Solution {
    static bool compare(const string &w1, const string &w2) {
        return w1.length() < w2.length();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        unordered_map<string, int> dp;
        int maxChainLength = 0;
        for(string word : words) {
            for(int i=0; i<word.length(); i++) {
                string predecessor = word;
                predecessor.erase(i, 1);
                dp[word] = max(dp[word], dp.find(predecessor) == dp.end() ? 1 : dp[predecessor] + 1);
                maxChainLength = max(maxChainLength, dp[word]);
            }
        }

        return maxChainLength;
    }
};



// *********** TRYING TO IMPLEMENT GRAPH SOLUTION ***********
// TODO
// https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/

class Node {
public:
    int length;
    unordered_set<string> words;
    Node(int length, unordered_set<string> words) {
        this->length = length;
        this->words = words;
    }
};

class Solution {

    // graph
    unordered_map<string, unordered_set<string>> children;

    // word.length() == pre.length() + 1
    void fillGraph(unordered_set<string> predecessors, unordered_set<string> words) {
        for(string word : words) {
            for(int i=0; i<word.length(); i++) {
                string oneLessCharWord = word;
                oneLessCharWord.erase(i, 1);
                for(string pre : predecessors) {
                    if(pre == oneLessCharWord) {
                        children[pre].insert(word);
                    }
                }
            }
        }
    }

    
    int maxLevel(unordered_set<string> firstLevelWords) {

     

    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        map<int, unordered_set<string>> lengthToWord;
        for(string word : words) {
            children[word] = {};
            lengthToWord[word.length()].insert(word);
        }

        vector<Node> allNodes;
        for(auto kv : lengthToWord) {
            int length = kv.first;
            unordered_set<string> lengthWords = kv.second;
            allNodes.push_back(Node(length, lengthWords));
        }
        
        for(int i=1; i<allNodes.size(); i++) {
            Node prevNode = allNodes[i-1];
            Node currNode = allNodes[i];
            if(prevNode.length + 1 == currNode.length) {
                fillGraph(prevNode.words, currNode.words);
            }
        }

        for(auto kv : children) {
            cout<<kv.first<<" => ";
            for(auto w : kv.second) {
                cout<<w<<", ";
            }
            cout<<endl;
        }

        // do this function correctly
        return maxLevel(allNodes[0].words);

    }
};