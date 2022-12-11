/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums) {
    
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;

    // n => no of sequences where tail is n 
    unordered_map<int, int> tail;
    for(int num : nums) {
        
        if(freq[num] == 0) continue;

        // using current number
        freq[num]--;
        
        // found a sequence in which tail 
        // is the previous number (num-1)
        // now, new tail will be = num
        if(tail[num-1] > 0) {
            tail[num-1]--;
            tail[num]++;
        }

        // create a new sequence of at least 3 numbers 
        // current num will be start of sequence
        else if(freq[num+1] > 0 && freq[num+2] > 0) {
            freq[num+1]--;
            freq[num+2]--;
            tail[num+2]++;
        }

        // don't know where to place current number
        else return false;
        
    }

    return true;
}

int main() {

    return 0;
}