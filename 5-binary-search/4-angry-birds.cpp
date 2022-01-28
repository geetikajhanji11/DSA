/**************************************************************

ANGRY BIRDS

There is a long wire along at straight line, which contains
N bird nests at positions x1, x2 ....xN.

There are B (B<=N) birds, which become angry towards
each other once put into a nest. To put the birds from
hurting each other you want to assign birds to nests such
that minimum distance between any two birds is as large
as possible. What is the largest minimum distance?

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

bool canPlaceBirds(vector<int> positions, int birds, int n, int distance) {

    // birds - 1 because one bird is at 0th position always
    int prevBirdPosition = positions[0];
    
    for(int i=1; i<n; i++) {
        cout<<"\nprevBirdPosition: "<<prevBirdPosition<<", currPosition: "<<positions[i];
        int currBirdPosition = positions[i];
        if(currBirdPosition - prevBirdPosition >= distance) {
            cout<<"\n1 Bird at "<<positions[i];
            birds--;
            prevBirdPosition = currBirdPosition;
        }
        // all birds are in position
        if(birds == 0) return true;
    }
    // some birds are left to be positioned
    return false;
}

int angryBirds(vector<int> positions, int birds) {

    // if positions are not sorted already, sort 
    sort(positions.begin(), positions.end());
    int n = positions.size();

    // final result variable
    int largestMinDistance = INT_MIN;
    
    // binary search 
    int low = 0;
    int high = positions[n-1] - positions[0];
    while(low <= high) {

        // this mid = distance between nests
        int mid = (low + high) / 2;
        cout<<"\nlow: "<<low<<" | high: "<<high<<" | mid: "<<mid;

        // birds can fit with this distance between them, 
        // increase distance => go right
        if(canPlaceBirds(positions, birds-1, n, mid)) {
            largestMinDistance = mid;
            low = mid + 1;
        } 

        // birds can't fit with this distance
        // reduce distance => go left
        else {
            high = mid - 1;
        }

        cout<<endl;
    }
    return largestMinDistance;
}

// main function
int main() {

    vector<int> positions{1, 2, 4, 8, 9};
    int birds = 3;

    int dist = angryBirds(positions, birds);
    cout<<"\nLargest Minimum Distance = "<<dist;

}