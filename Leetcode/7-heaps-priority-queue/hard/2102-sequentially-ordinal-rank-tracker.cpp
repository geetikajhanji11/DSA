/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** TWO HEAPS **************
class Scenery {
public:
    string name;
    int score;
    Scenery(string name, int score) {
        this->name = name;
        this->score = score;
    }
};

class MinCompare {
public:
    // score small, name high
    bool operator()(Scenery s1, Scenery s2) {
        if(s1.score == s2.score) {
            return s1.name < s2.name;
        }
        return s1.score > s2.score;
    }
};

class MaxCompare {
public:
    // score high, name small
    bool operator()(Scenery s1, Scenery s2) {
        if(s1.score == s2.score) {
            return s1.name > s2.name;
        }
        return s1.score < s2.score;
    }
};

class SORTracker {
    int i;

    // top i scored sceneries
    priority_queue<Scenery, vector<Scenery>, MinCompare> minHeap; // left
    
    // rest of the sceneries with highest score scenery on top
    // top of this is always the answer
    priority_queue<Scenery, vector<Scenery>, MaxCompare> maxHeap; // right

public:
    SORTracker() {
        i = 0;
    }
    
    // i does not change
    void add(string name, int score) {
        Scenery scenery(name, score);

        // add to min heap
        minHeap.push(scenery);
        if(minHeap.size() == i + 1) {
            Scenery poppedScenery = minHeap.top(); minHeap.pop();
            maxHeap.push(poppedScenery);
        } 
    }
    
    string get() {
        Scenery poppedScenery = maxHeap.top(); maxHeap.pop();
        minHeap.push(poppedScenery);
        i++;
        return poppedScenery.name;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */






// ************** TLE ************** 
class SORTracker {
    int index;
    set<pair<int, string>> s;

public:
    SORTracker() {
        this->index = 0;
    }
    
    void add(string name, int score) {
        s.insert({-score, name});
    }
    
    string get() {
        auto itr = s.begin();
        advance(itr, index);
        string result = (*itr).second;
        index++;
        return result;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */