/******************************************************************************

RUNNING MEDIAN

Given a running stream of integers, write an efficient algorithm to output
median of numbers read so after every input.

Sample input:
    10, 5, 2, 3, 0, 12, 18, 20, 22
    
Sample output:
    10, 7.5, 5, 4, 3, 4, 5, 7.5, 10

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include<algorithm>
using namespace std;

vector<double> runningMedian(vector<int> arr) {
    priority_queue <double> leftHeap; // max heap
    priority_queue <double, vector<double>, greater<double> > rightHeap; // min heap
    
    vector<double> result;
    
    leftHeap.push(arr[0]);
    double currMedian = arr[0];
    result.push_back(currMedian);
    
    for(int i=1; i<arr.size(); i++) {
        
        // left heap > right heap
        if(leftHeap.size() > rightHeap.size()) {
            
            // goes in left heap
            if(arr[i] < currMedian) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(arr[i]);
                
            } 
            
            // goes in right heap
            else {
                rightHeap.push(arr[i]);
            }
            
            currMedian = (leftHeap.top() + rightHeap.top()) / 2;
        }
        
        
        // right heap > left heap
        else if(rightHeap.size() > leftHeap.size()) {
            
            // goes in right heap
            if(arr[i] > currMedian) {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(arr[i]);
                
            } 
            
            // goes in left heap
            else {
                leftHeap.push(arr[i]);
            }
            
            currMedian = (leftHeap.top() + rightHeap.top()) / 2;
        }
        
        // left heap = right heap
        else {
            if(arr[i] < currMedian) {
                leftHeap.push(arr[i]);
                currMedian = leftHeap.top();
            } else {
                rightHeap.push(arr[i]);
                currMedian = rightHeap.top();
            }
        }
        result.push_back(currMedian);
        
    }
    return result;
}

int main() {

    vector<int> arr{10, 5, 2, 3, 0, 12, 18, 20, 22};
    vector<double> result = runningMedian(arr);
    
    cout<<"\nRunning Median: ";
    for(double median : result) {
        cout<<median<<" ";
    }
    

    return 0;
}
