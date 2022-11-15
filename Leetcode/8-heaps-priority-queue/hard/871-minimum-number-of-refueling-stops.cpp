/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        // regard target as a station
        stations.push_back({target, 0});

        // maxHeap of the fuels that we missed
        priority_queue<int> missedFuels;

        int currMiles = 0;
        int currFuel = startFuel;
        int totalStops = 0;
        int prevPosition = 0;

        for(auto station : stations) {

            int stationPosition = station[0];
            int stationFuel = station[1];

            // calculate the distance between two stations
            int distanceToTravel = stationPosition - prevPosition;
            prevPosition = stationPosition;

            // we are running out of fuel
            // use Time machine to get some fuel we missed
            while(!missedFuels.empty() && currFuel < distanceToTravel) {
                currFuel += missedFuels.top(); missedFuels.pop();
                totalStops++;
            } 

            if(currFuel < distanceToTravel) return -1;

            currFuel -= distanceToTravel;
            missedFuels.push(stationFuel);

        }

        return totalStops;

    }
};