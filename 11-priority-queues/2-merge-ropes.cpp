/******************************************************************************

Given N ropes each hyaving a different size, your task is to join the ropes
together. The cost of joining 2 ropes of different sizes X and Y is (X + Y).
Find the minimum cost to join all the ropes together.

Input:
    N = 4
    Ropes = {4, 3, 2, 6}
    
Output:
    29

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include<algorithm>
using namespace std;

class Compare {
    public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int minimumCost(vector<int> ropes) {
    priority_queue<int, vector<int>, Compare> heap;
    
    // inserting all elements in the heap
    for(int rope : ropes) {
        heap.push(rope);
    }
    
    // take 2 minimum ropes from heap
    // add them into cost
    int cost = 0;
    while(heap.size() != 1) {
        
        int rope1 = heap.top();
        heap.pop();
        
        int rope2 = heap.top();
        heap.pop();
        
        int newRope = rope1 + rope2;
        cost += newRope;
        heap.push(newRope);
        
    }
    
    return cost;
}

int main() {

    vector<int> ropes{4, 3, 2, 6};
    int cost = minimumCost(ropes);
    
    cout<<"\nMinimum cost = "<<cost;
    

    return 0;
}
