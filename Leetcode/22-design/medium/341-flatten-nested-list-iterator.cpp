/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


// ******************* DISCUSS SOLUTION *******************
// ignore error
class NestedIterator {

    deque<NestedInteger*> q;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0; i<nestedList.size(); i++) {
            q.push_back(&nestedList[i]);
        }
    }
    
    int next() {
        int num = q.front()->getInteger();
        q.pop_front();

        return num;
    }
    
    bool hasNext() {
        while(!q.empty() && !(q.front()->isInteger())) {
            
            NestedInteger* ni = q.front(); 
            q.pop_front();
            vector<NestedInteger> &vect = ni->getList();
            for(int i=vect.size()-1; i>=0; i--) {
                q.push_front(&vect[i]);
            }
        } 
        return !q.empty();
    }
};

// ******************* MY SOLUTION *******************
class NestedIterator {

    vector<int> newlyFlattenedList;
    int i;

    vector<int> flattenedList(int i, vector<NestedInteger> nestedList) {
        if(i >= nestedList.size()) return {};

        vector<int> currentList;
        vector<int> restOfTheList;
        
        if(nestedList[i].isInteger()) {
            currentList = {nestedList[i].getInteger()};    
        } else {
            currentList = flattenedList(0, nestedList[i].getList());
        }

        restOfTheList = flattenedList(i+1, nestedList);

        currentList.insert(currentList.end(), restOfTheList.begin(), restOfTheList.end());
        return currentList;
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        newlyFlattenedList = flattenedList(0, nestedList);
        i = 0;
    }
    
    int next() {
        int num = newlyFlattenedList[i];
        i++;
        return num;
    }
    
    bool hasNext() {
        return i < newlyFlattenedList.size();
    }
};