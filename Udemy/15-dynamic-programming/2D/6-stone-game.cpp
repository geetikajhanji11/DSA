/*******************************************************************
https://www.youtube.com/watch?v=uhgdXOlGYqE&t=420s&ab_channel=NeetCode

STONE GAME

Alice and Bob play a game with piles of stones. There are an even 
number of piles arranged in a row, and each pile has a positive 
integer number of stones piles[i].
The objective of the game is to end with the most stones. 
The total number of stones across all the piles is odd, so there 
are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, 
a player takes the entire pile of stones either from the beginning 
or from the end of the row. This continues until there are no more 
piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins 
the game, or false if Bob wins.

Example 1:

    Input: piles = [5,3,4,5]
    Output: true

    Explanation: 
    Alice starts first, and can only take the first 5 or the last 5.
    Say she takes the first 5, so that the row becomes [3, 4, 5].
    If Bob takes 3, then the board is [4, 5], and Alice takes 5 to 
    win with 10 points. If Bob takes the last 5, then the board is 
    [3, 4], and Alice takes 4 to win with 9 points.
    This demonstrated that taking the first 5 was a winning move 
    for Alice, so we return true.

Example 2:

    Input: piles = [3,7,2,3]
    Output: true

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int alice_points(int i, int j, vector<int> stones, vector<vector<int>> &dp) {

    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // when even => alice makes a choice, otherwise
    // bob makes a choice so we don't include that
    // stones[i] in our answer
    bool even = (j - i) % 2 == 0 ? true : false;

    int left = 0;
    int right = 0;
    if(even) {
        left = stones[i];
        right = stones[j];
    }

    int pick_left = left + alice_points(i+1, j, stones, dp);
    int pick_right = right + alice_points(i, j-1, stones, dp);

    return dp[i][j] = max(pick_left, pick_right);
}

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int total = accumulate(piles.begin(), piles.end(), 0);
    int alice = alice_points(0, n - 1, piles, dp);
    int bob = total - alice;
    // cout<<"\nalice = "<<alice<<", bob = "<<bob;

    if(alice > bob) return true;
    return false;
}

int main() {

    vector<int> stones = {5,3,4,5};
    stoneGame(stones);
    return 0;
}