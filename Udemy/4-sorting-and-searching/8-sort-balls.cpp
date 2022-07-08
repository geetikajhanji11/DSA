/**************************************************************

DNF ALGORITHM

JUGGLING BALLS
https://www.youtube.com/watch?v=4xbWSRZHqac&t=12s&ab_channel=NeetCode

Given an array containing balls of Red, Blue and Green Color 
in a random order. Your goal is to arrange these balls in 
sorted order - Red Balls, followed by Blue and then Green Balls. 
Red balls are denoted using number 0, Blue using 1 and Green 
using 2.

Note: Try to solve the problem in a single scan of the array 
without using extra space.

Hint - read about DNF Algorithm 

Input
    {0, 0, 1, 2, 0, 1, 2, 0}

Output
    {0, 0, 0, 0, 1, 1, 2, 2}

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

// sort the balls in place in a single pass (O(N) time, O(1) space)
vector<int> sortBalls(vector<int> balls){
    
    int left = 0;
    int right = balls.size() - 1;

    int i = 0;

    while(i < right && left < right) {
        if(balls[i] == 0) {
            swap(balls[i], balls[left]);
            left++;
            i++;
        }
        else if(balls[i] == 2) {
            swap(balls[i], balls[right]);
            right--;
        } else {
            i++;
        }
    }
        
    
    return balls;
}

// main function
int main() {

    vector<int> balls{0, 0, 1, 2, 0, 1, 2, 0};

    vector<int> sortedBalls = sortBalls(balls);
    cout<<"\nBalls = ";
    for(int ball : sortedBalls) {
        cout<<ball<<" ";
    }
    
    return 0;

}