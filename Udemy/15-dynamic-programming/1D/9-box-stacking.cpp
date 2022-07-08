/*******************************************************************
 * BOX STACKING
 * 
 * We are given an array of boxes. Each box is represented using
 * 3 integers denoting height, width, depth. Our goal is to stack
 * up the boxes and maximize the total height of the stack.
 * 
 * You can't rotate any box, i.e., integers in each box must
 * represnt [width, depth, height] at all times.
 * 
 * A box must have strictly smaller width, depth and height 
 * than any other box below it.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2) {
    return b1[2] < b2[2];
}

// returns true if b1 can be places on top of b2
bool canPlaceOnTop(vector<int> b1, vector<int> b2) {
    return b1[0] < b2[0] && b1[1] < b2[1] && b1[2] < b2[2]; 
}

int box_stacking(vector<vector<int>> boxes) {

    // sort the boxes according to their height
    sort(boxes.begin(), boxes.end(), compareBoxes);

    // dp vector
    vector<int> dp(boxes.size()+1, 0);
    for(int i=0; i<boxes.size(); i++) {
        dp[i] = boxes[i][2];
    }

    // iterative approach
    int max_height = INT_MIN;

    // i=1 => first box cannot be a bottom
    // ith box is BOTTOM BOX
    // jth box is TOP BOX 
    for(int i=1; i<boxes.size(); i++) { 
        for(int j=0; j<i; j++) {
            if(canPlaceOnTop(boxes[j], boxes[i])) {
                int bottom_box_height = boxes[i][2];
                dp[i] = max(dp[i], dp[j] + bottom_box_height);
                max_height = max(max_height, dp[i]);
            }
        }
    }

    return max_height;
}

int main() {

    vector<vector<int>> boxes = {
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5},
    };
    cout<<box_stacking(boxes);

    return 0;
}