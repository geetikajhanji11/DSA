/*******************************************************************
Implement data structure that gets the median from a data stream

Max heap of lower values & min heap of higher values, access to mids

Time: O(log n) + O(1)
Space: O(n)
*******************************************************************/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> max_heap; // left side
    priority_queue <int, vector<int>, greater<int>> min_heap; // right side

    MedianFinder() {}
    
    void addNum(int num) {

        if(min_heap.empty()) {
            min_heap.push(num);
            return;
        }

        // balance the two heaps before finding median
        int left_size = max_heap.size();
        int right_size = min_heap.size();

        if(left_size > right_size) {
            int median = max_heap.top();
            if(num < median) { // should go in left (max_heap)
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            } else { // should go in right (min_heap)
                min_heap.push(num);
            }
        } 

        else {
            int median = min_heap.top();
            if(num < median) { // should go in left (max_heap)
                max_heap.push(num);
            } else { // should go in right (min_heap)
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }   
        }

        
    } 
    
    double findMedian() {
        // find the new median and update the variable
        int left_size = max_heap.size();
        int right_size = min_heap.size();

        double median = 0.0;
        if(left_size == right_size) {
            median = (max_heap.top() + min_heap.top()) / 2.0;
        } else if(left_size < right_size) {
            median = min_heap.top();
        } else {
            median = max_heap.top();
        }

        return median;
    }
};

int main() {

    return 0;
}