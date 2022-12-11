/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//   Below is the interface for Iterator, which is already defined for you.
//   **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {

    bool isFast;
    int prevData;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        isFast = false;
        prevData = -1;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {

        if(!isFast) {
            isFast = true;
            prevData = Iterator::next();
            return prevData;
        }

        return prevData;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {

	    if(isFast) {
            isFast = false;
            return prevData; 
        } 

        return Iterator::next();
	}
	
	bool hasNext() const {

	    if(isFast) return true;
        return Iterator::hasNext();
	}
};

// ************ OTHER SOLUTION ************
class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {}

    int peek() {
        return Iterator(*this).next();
    }

    int next() {
        return Iterator::next();
    }

    bool hasNext() const {
        return Iterator::hasNext();
    }
};
