/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ******************* ACTUAL *******************
class MyHashSet {
    int prime;
    vector<list<int>> lists;

    int getHash(int &key) {
        return key % prime;
    }

    list<int>::iterator getIter(int key) {
        int hash = getHash(key);
        auto iter = find(lists[hash].begin(), lists[hash].end(), key);
        return iter;
    }

public:
    MyHashSet() {
        prime = 10007;
        lists.resize(prime);
    }
    
    void add(int key) {
        int hash = getHash(key);
        if(contains(key)) return;
        lists[hash].push_back(key);
    }
    
    void remove(int key) {
        int hash = getHash(key);
        auto iter = getIter(key);

        if(iter == lists[hash].end()) return;

        lists[hash].erase(iter);
    }
    
    bool contains(int key) {
        int hash = getHash(key);
        return getIter(key) != lists[hash].end();
    }
};


// ******************* troll answer *******************
class MyHashSet {
    vector<bool> exists;
public:
    MyHashSet() {
        exists.resize(1000001, false);
    }
    
    void add(int key) {
        if(exists[key]) return;
        exists[key] = true;
    }
    
    void remove(int key) {
        exists[key] = false;
    }
    
    bool contains(int key) {
        return exists[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */