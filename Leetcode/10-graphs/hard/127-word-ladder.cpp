/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    // check if endword exists in list or not
    // if does not exist, not possible to create word ladder
    bool found_end_word = false;
    for(string word : wordList) {
        if(word == endWord) {
            found_end_word = true;
            break;
        }
    } 
    if(!found_end_word) return 0;

    // add beginWord in wordList since it does not exist initially
    wordList.push_back(beginWord);

    // build the adjacency list
    unordered_map<string, vector<string>> adj_list;
    for(string word : wordList) {
        string pattern = word;
        for(int i=0; i<word.length(); i++) {
            pattern[i] = '*';
            adj_list[pattern].push_back(word);
            pattern[i] = word[i];
        }
    }

    // perform shortest BFS on the graph
    unordered_set<string> visited;
    queue<string> q;

    q.push(beginWord);
    visited.insert(beginWord);
    int result = 1;

    while(!q.empty()) {
        int curr_q_size = q.size();
        while(curr_q_size != 0) {

            string word = q.front();
            q.pop();
            if(word == endWord) return result;

            vector<string> neighbours;
            string pattern = word;
            for(int i=0; i<word.length(); i++) {
                pattern[i] = '*';
                vector<string> curr_nbrs = adj_list[pattern];
                neighbours.insert(neighbours.end(), curr_nbrs.begin(), curr_nbrs.end());
                pattern[i] = word[i];
            }

            for(string neighbour : neighbours) {
                if(visited.find(neighbour) != visited.end()) continue;
                q.push(neighbour);
                visited.insert(neighbour);
            }
            curr_q_size--;
        }
        result++;
    }
    return 0;
}

int main() {

    vector<string> wordSet = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";

    cout<<ladderLength(beginWord, endWord, wordSet);
    return 0;
}