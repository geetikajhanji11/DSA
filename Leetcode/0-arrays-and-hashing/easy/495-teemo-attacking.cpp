/*******************************************************************
        when a continous series finishes,
        add e - s + duration
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        
        if(timeSeries.size() == 0) return 0;

        int start = timeSeries[0];
        int end = start + duration - 1;
        int prev = start;
        int sum = 0;

        for(int i=1; i<timeSeries.size(); i++) {
            
            // series continue
            if(timeSeries[i] <= end) { 
                // do nothing
                // let series grow
            } 
            
            // series end
            else {
                sum += (prev - start + duration);
                start = timeSeries[i];
            }

            // for next iteration
            end = timeSeries[i] + duration - 1;
            prev = timeSeries[i];
        }
        
        sum += (prev - start + duration);

        return sum;
        
    } 
};