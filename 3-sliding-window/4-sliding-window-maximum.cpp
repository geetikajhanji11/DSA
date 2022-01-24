/**************************************************************

https://www.youtube.com/watch?v=DfljaUwZsOk

Given an array of integers and an integer K, return a vector 
containing maximum for each and every contiguous subarray of 
size k

input:
    k = 3
    input = [1, 2, 3, 1, 4, 5, 2, 3, 6]
output:
    output = [3, 3, 4, 5, 5, 5, 6]

Maximum of 1, 2, 3 = 3
Maximum of 2, 3, 1 = 3
Maximum of 3, 1, 4 = 4
Maximum of 1, 4, 5 = 5
Maximum of 4, 5, 2 = 5
Maximum of 5, 2, 3 = 5
Maximum of 2, 3, 6 = 6

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

vector<int> maxInWindow(vector<int> input,int k) {

    vector<int> result;

    deque<int> Q(k);

    int i;

    // process only the first K elements
    for(i=0; i<k; i++) {
        while(!Q.empty() && input[i] > input[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for(; i<input.size(); i++) {
        result.push_back(input[Q.front()]);

        // contract window if front element
        // of queue is outside index bounds 
        while(!Q.empty() && Q.front() <= i-k) {
            Q.pop_front();
        }

        // contract if next element > back of dequeue
        while(!Q.empty() && input[i] > input[Q.back()]) {
            Q.pop_back();
        }

        // add to back of queue
        Q.push_back(i);
    }

    result.push_back(input[Q.front()]);

    return result;
    
}

// main function
int main() {

    vector<int> input{1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    vector<int> result = maxInWindow(input, k);
    cout<<"\nAnswer = ";
    for(int num : result) {
        cout<<num<<" ";
    }

    return 0;

}