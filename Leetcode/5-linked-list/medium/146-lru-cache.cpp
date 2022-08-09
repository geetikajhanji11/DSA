/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int key;
    int value;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {

    int capacity;
    list<Node> l;
    unordered_map<int, list<Node>::iterator> m;

public:

    LRUCache(int capacity) {
        this->capacity = capacity < 1 ? 1 : capacity;
    }
    
    int get(int key) {

        // key is not present in the list
        if(m.find(key) == m.end()) return -1;

        // key is present
        auto it = m[key];
        int value = it->value;

        l.push_front(*it);
        l.erase(it);
        m[key] = l.begin();
        return value;

    }
    
    void put(int key, int value) {

        // key already exists in the cache
        // remove this key from the doubly linked list
        // and the map (since we need to update it)
        if(m.find(key) != m.end()) {
            auto it = m[key];
            l.erase(it);
            m.erase(key);
        }

        // new key value pair
        // if cache is full,
        // evict least recently used
        if(l.size() == capacity) {
            Node last = l.back();
            m.erase(last.key);
            l.pop_back();
        } 

        // push this new Node in the 
        // beginning of the linked list
        // since they are recent now
        Node new_node(key, value);
        l.push_front(new_node);
        m[key] = l.begin();

    }
};

int main() {

    return 0;
}