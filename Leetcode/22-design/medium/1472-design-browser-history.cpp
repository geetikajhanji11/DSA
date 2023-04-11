/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** DYNAMIC ARRAY O(1) *************** 

class BrowserHistory {
    vector<string> history;
    int currIdx;
    int endIdx;

public:
    BrowserHistory(string homepage) {
        history = {homepage};
        currIdx = 0;
        endIdx = 0;
    }
    
    void visit(string url) {
        if(currIdx + 1 == history.size()) {
            history.push_back(url);
            currIdx++;
            endIdx++;
        } else {
            currIdx++;
            history[currIdx] = url;
            endIdx = currIdx;
        }
    }
    
    string back(int steps) {
        currIdx = max(0, currIdx - steps);
        return history[currIdx];
    }
    
    string forward(int steps) {
        currIdx = min(currIdx + steps, endIdx);
        return history[currIdx];
    }
};


// *************** DOUBLY LINKED LIST O(steps) *************** 
class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string s) {
        this->url = s;
        this->prev = NULL;
        this->next = NULL;
    }
};

class BrowserHistory {
    Node* curr;

public:
    BrowserHistory(string homepage) {
        Node* newNode = new Node(homepage);
        curr = newNode;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    
    string back(int steps) {
        while(steps > 0 && curr->prev != NULL) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps > 0 && curr->next != NULL) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

