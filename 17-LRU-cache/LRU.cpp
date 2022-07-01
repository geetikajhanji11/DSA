/*******************************************************************
 * LRU CACHE
 * 
 * Implement a data structure, for LRU Cache Implementation,
 * which supports following operations in O(1) time.
 * 
 * Operation:
 *      insert(key, value)
 *      getValue(key)
 *      getMostRecentKey()
 * 
 * Also the class should have maxSize property which is to set
 * the size of the cache. It represents the max number of key
 * value pairs that can be stored inside the cache at one time.
 * If a key value pair is inserted in the cache when the cache
 * is full, then the least recently used key value pair should 
 * be deleted and the new one should be inserted. If the key
 * already exists in the cache, then simply the value of the key
 * can be updated with the new value.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// node to store the data (Linked List)
class Node {
public:
    string key;
    int value;
    Node(string key, int value) {
        this->key = key;
        this->value = value;
    }
};

// LRU Cache data structure
class LRUCache {
public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator> m;

    LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
    }

    void insert(string key, int value) {

        // 1. UPDATE
        // present in the cache & map 
        if(m.count(key) != 0) {
            auto it = m[key];
            it->value = value;
        }

        else {
            // check if cache is full or not
            // if full, remove the least recently
            // used item from cache
            if(l.size() == maxSize) {
                Node lastNode = l.back(); // get last node from dll
                m.erase(lastNode.key); // erase from hashmap
                l.pop_back(); // remove from dll
            }

            Node newNode(key, value);
            l.push_front(newNode);
            m[key] = l.begin();

        }

    }

    int* getValue(string key) {
        // check if key exists in map
        // key does not exist
        if(m.count(key) == 0) return NULL;

        // key exists
        auto it = m[key];
        int value = it->value;

        // push node to front
        l.push_front(*it);
        l.erase(it);
        m[key] = l.begin();
        return &l.begin()->value;
    }

    string getMostRecentKey() {
        return l.front().key;
    }
};

int main() {

    LRUCache lru(3);
    lru.insert("mango", 10);
    lru.insert("apple", 20);
    lru.insert("guava", 30);
    cout<<lru.getMostRecentKey()<<endl;

    lru.insert("mango", 40);
    cout<<lru.getMostRecentKey()<<endl;

    int *value = lru.getValue("mango");
    if(value != NULL) cout<<"Value of mangoes = "<< *value<<endl;

    lru.insert("banana", 20);

    if(lru.getValue("apple") == NULL) {
        cout<<"apple doesn't exist.\n";
    }

    if(lru.getValue("guava") == NULL) {
        cout<<"guava doesn't exist.\n";
    }

    if(lru.getValue("banana") == NULL) {
        cout<<"banana doesn't exist.\n";
    }

    if(lru.getValue("mango") == NULL) {
        cout<<"mango doesn't exist.\n";
    }

    cout<<lru.getMostRecentKey()<<endl;

    return 0;
}