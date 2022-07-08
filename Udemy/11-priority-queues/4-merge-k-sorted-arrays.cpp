/******************************************************************************

K WAY MERGE

The K way merge problem consists of mering k sorted arrays to produce
a single sorted array with the same elements.
K-way merges are used in external sorting procedures.
External sorting algorithms are a class of sorting algorithms that 
can handle massive amounts of data.

GIven a k-sorted arrays of different sizes, produce a single sorted array.

Sample input:
    k = 3
    a1 = {1, 3, 15}
    a2 = {2, 4, 6}
    a3 = {0, 9, 10, 11}
    
Sample output:
    {0, 1, 2, 3, 4, 6, 9, 10, 11, 15}

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include<algorithm>
using namespace std;

// custom class to store additional info
class Element {
    
    public:
    
    int num;
    int index;
    int arrayIndex;
    int arraySize;
    
    Element(int n, int i, int ai, int as) {
        num = n;
        index = i;
        arrayIndex = ai;
        arraySize = as;
    }
    
    bool isLastElement() {
        return index == arraySize - 1;   
    }
};

// comparison class for min heap implementation
class Compare {
public:
    bool operator()(Element A, Element B) {
        return A.num > B.num; // min heap
    }
};

// for merging k sorted arrays
vector<int> mergeKArrays(vector<vector<int> > arrays){

    priority_queue <Element, vector<Element>, Compare > minHeap;
    vector<int> result;
    
    // insert all the numbers at 0th index of each array into min heap
    //      num = number at 0th index of current array;
    //      index = index of this number in current array;
    //      arrayIndex = index of current array in 2d matrix;
    //      arraySize = size of current array;
    for(int i=0; i<arrays.size(); i++) {
        minHeap.push(
            Element(
                arrays[i][0], 
                0, 
                i, 
                arrays[i].size()
            )
        );
    }
    
    // while loop until minheap is empty
    while(!minHeap.empty()) {
        
        // get current Element, then pop it
        // this is the minimum element yet encountered
        Element curr = minHeap.top();
        minHeap.pop();
        
        // push it into result
        result.push_back(curr.num);
        
        // if this is not the last element 
        // of th array in which it exists
        if(!curr.isLastElement()) {
            
            // insert the next element 
            // of the array in which the 
            // current element belonged to
            Element nextEl = Element(
                arrays[curr.arrayIndex][curr.index + 1], // next int in array
                curr.index + 1, // index increases by 1, meaning next element
                curr.arrayIndex, // same array to which it belongs
                curr.arraySize // size of same array remains the same
            );
            
            // add next element in min heap
            minHeap.push(nextEl);
        }
        
    }

    return result;
    
}

int main() {

    vector<vector<int>> arrays{
        {10, 15, 20, 30},
        {2, 5, 8, 14, 24},
        {0, 11, 60, 90}
    };
    vector<int> result = mergeKArrays(arrays);
    
    cout<<"\nAfter merging: ";
    for(int num : result) {
        cout<<num<<" ";
    }
    
    return 0;
}
