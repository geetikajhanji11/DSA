/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Structure for key-value pair
class Node {
public:
    int key;
    int value;
    int freq;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->freq = 1;
    }
};

class LFUCache {

    int capacity;
    int size;
    int minFreq;
    unordered_map<int, list<Node>::iterator> keyToItr;
    unordered_map<int, list<Node>> freqToList;
    
public:

    // constructor
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    // returns the value of the key if the key exists in the cache
    // otherwise, returns -1.
    int get(int key) {  
        
        // key does not exist
        if(keyToItr.find(key) == keyToItr.end()) return -1;

        // key already exists
        auto it = keyToItr[key];

        // get the node's details
        int oldFreq = it->freq;
        int value = it->value;

        // update the node's frequency
        int newFreq = oldFreq + 1;
        it->freq = newFreq;

        // remove this node from old freq list
        // and push to new freq list
        //and update the key->itr map
        freqToList[newFreq].push_front(*it);
        freqToList[oldFreq].erase(it);
        keyToItr[key] = freqToList[newFreq].begin();
        
        // update min freq
        if(freqToList[minFreq].size() == 0) {
            minFreq++;
        }

        // return value
        return value;
    }
    
    void put(int key, int value) {

        // capacity is not enough to insert
        // a new node
        if(capacity <= 0) return;

        // key already exists in the map
        // update value and return
        int storedValue = get(key);
        if(storedValue != -1) {
            keyToItr[key]->value = value; 
            return;
        }

        // key does not exist in the list
        // and capacity is full
        // remove the LFU node
        if(size >= capacity) {
            Node evictNode = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            keyToItr.erase(evictNode.key);
            size--;
        }

        // key does not exist in the list
        // there is space in the cache
        // insert a brand new node in cache
        Node newNode(key, value);
        freqToList[1].push_front(newNode);
        keyToItr[key] = freqToList[1].begin();
        size++;
        minFreq = 1;  
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */