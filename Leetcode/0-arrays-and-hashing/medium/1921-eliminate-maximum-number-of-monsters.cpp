/*******************************************************************
[50,50,30,30,30,30,30,30,20]
[49,48,10,10,10,10,10,9,1]
[1,3,4]
[1,1,1]
[1,1,2,3]
[1,1,1,1]
[3,2,4]
[5,3,2]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = dist.size();
        vector<int> monsterReachTime(n);

        for(int i=0; i<n; i++) {
            int time = ceil((float) dist[i] / (float) speed[i]);
            monsterReachTime[i] = time;
        }

        sort(monsterReachTime.begin(), monsterReachTime.end());

        int monstersKilled = 0;
        for(int time=0; time<n; time++) {
            if(monsterReachTime[time] <= time) break;
            monstersKilled++;
        }

        return monstersKilled;
    }
};