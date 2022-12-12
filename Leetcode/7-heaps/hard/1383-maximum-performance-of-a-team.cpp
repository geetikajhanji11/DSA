/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Team {
public:
    int speed;
    int efficiency;
    Team(int speed, int efficiency) {
        this->speed = speed;
        this->efficiency = efficiency;
    }
};

// maximize size for current lowest efficiency
// min heap on basis of speed
class HeapCompare {
public:
    bool operator()(Team t1, Team t2) {
        return t1.speed > t2.speed;
    }
};

int MOD = pow(10, 9) + 7;

class Solution {

    // decreasing order of efficiency
    static bool customSort(Team t1, Team t2) {
        return t1.efficiency > t2.efficiency;
    }

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Team> teams;
        for(int i=0; i<n; i++) {
            teams.push_back(Team(speed[i], efficiency[i]));
        }      

        sort(teams.begin(), teams.end(), customSort);

        // size = k
        priority_queue<Team, vector<Team>, HeapCompare> minHeap;

        long long result = 0;
        long long speedSum = 0;

        for(Team team : teams) {

            // pop from minHeap
            if(minHeap.size() == k) {
                speedSum -= minHeap.top().speed;
                minHeap.pop();
            }

            // assume current efficiency to be lowest
            long long lowestEfficiency = team.efficiency;
            speedSum += team.speed;
            minHeap.push(team);


            result = max(result, lowestEfficiency * speedSum);
        }

        return result % MOD;

    }
};