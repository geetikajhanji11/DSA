/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//     void recur(int i, int j, vector<int>& cardPoints, int k, int curr_sum, int &max_score) {
//         if(i >= cardPoints.size() || j < 0) return;
        
//         max_score = max(max_score, curr_sum);
        
//         if(k == 0) return;
        
//         recur(i+1, j, cardPoints, k-1, curr_sum+cardPoints[i], max_score);
//         recur(i, j-1, cardPoints, k-1, curr_sum+cardPoints[j], max_score);
        
//     }   
    
//     int maxScore(vector<int>& cardPoints, int k) {
//         int max_score = 0;
//         recur(0, cardPoints.size()-1, cardPoints, k, 0,  max_score);
//         return max_score;
//     }

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int total_sum = 0;
    int window_size = n - k;
    int window_sum = 0;
    
    // calculating the total sum of array
    for(int card : cardPoints) total_sum += card;
    
    // calculating the sum of the window
    for(int i=0; i<window_size; i++) window_sum += cardPoints[i];
    
    int left = 0;
    int right = window_size-1;
    int min_window_sum = window_sum;
    
    // sliding window in which
    // we have to keep the window sum minimum
    while(right >= 0 && right < n) {
        right++;
        if(right >= n) break;
        window_sum = window_sum + cardPoints[right] - cardPoints[left];
        min_window_sum = min(min_window_sum, window_sum);
        left++;
        
    }
    
    return total_sum - min_window_sum;
}

int main() {

    return 0;
}

/*
[2,2,2]
2
[9,7,7,9,7,7,9]
7
[11,49,100,20,86,29,72]
4
*/