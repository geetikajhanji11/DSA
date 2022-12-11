/*******************************************************************
Given array of stones to smash, return smallest possible weight of last stone
If x == y both stones destroyed, if x != y stone x destroyed, stone y = y - x
Ex. stones = [2,7,4,1,8,1] -> 1, [2,4,1,1,1], [2,1,1,1], [1,1,1], [1]

Max heap, pop 2 biggest, push back difference until no more 2 elements left

Time: O(n log n)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;

    for(int stone : stones) maxHeap.push(stone);

    while(maxHeap.size() > 1) {
        // 1. get the first two heaviest stones
        int stone_1 = maxHeap.top();
        maxHeap.pop();
        int stone_2 = maxHeap.top();
        maxHeap.pop();

        // 2. calculate
        int new_stone = abs(stone_1 - stone_2);
        if(new_stone == 0) continue;

        // 3. if stone left, push in heap 
        maxHeap.push(new_stone);

    }

    if(maxHeap.size() == 1) return maxHeap.top();
    else return 0;
}

int main() {

    return 0;
}