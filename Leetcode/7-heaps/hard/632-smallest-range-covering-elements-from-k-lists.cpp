/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Element {
public:
    int num;
    int listIndex;
    int i;
    Element(int num, int listIndex, int i) {
        this->num = num;
        this->listIndex = listIndex;
        this->i = i;
    }
};

class Compare {
public:
    bool operator()(Element e1, Element e2) {
        return e1.num > e2.num;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        // number of lists = k
        int k = nums.size();

        vector<int> resultRange = {INT_MIN, INT_MAX}; // result 
        int resultRangeSize = INT_MAX; // minimize this

        // min heap of size k
        priority_queue<Element, vector<Element>, Compare> minHeap;
        
        // insert all 0th index elements of each list in minheap first
        int maxNum = INT_MIN; // keep track of max element in minheap
        for(int listIndex=0; listIndex<k; listIndex++) {
            int num = nums[listIndex][0];
            maxNum = max(maxNum, num);
            Element element(num, listIndex, 0);
            minHeap.push(element);
        }

        // loop until any one of the lists is exhausted
        while(!minHeap.empty()) {

            // pop the top element of minheap
            Element minElement = minHeap.top(); minHeap.pop();

            // calculate the range size
            int currRangeSize = maxNum - minElement.num + 1; 
            if(currRangeSize < resultRangeSize) {
                resultRangeSize = currRangeSize;
                resultRange = {minElement.num, maxNum};
            }

            // get the next element that has to be inserted in minheap
            int nextI = minElement.i + 1;
            if(nextI == nums[minElement.listIndex].size()) {
                break; // list has been exhausted
            }
            int nextNum = nums[minElement.listIndex][nextI];
            Element nextElement(nextNum, minElement.listIndex, nextI);

            // update maxNum which is max of current k elements in minheap
            maxNum = max(maxNum, max(nextNum, minHeap.top().num));

            // insert next element in minheap
            minHeap.push(nextElement);
        }

        return resultRange;

    }
};