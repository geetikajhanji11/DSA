/*******************************************************************
HEAP APPROACH
-------------
TIME: O(NlogN)
SPACE: O(N)


LINEAR TRAVERSAL APPROACH
-------------------------
TIME: O(N)
SPACE: O(N)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** HEAP SOLUTION **************
class Solution {

    class Trip {
        public:
        int passengers;
        int from;
        int to;
        Trip(int passengers, int from, int to) {
            this->passengers = passengers;
            this->from = from;
            this->to = to;
        }
    };

    static bool tripSort(Trip t1, Trip t2) {
        if(t1.from == t2.from) return t1.to < t2.to;
        return t1.from < t2.from;
    }

    class HeapCompare {
    public:
        bool operator()(Trip t1, Trip t2) {
            return t1.to > t2.to;
        }
    };

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        // sorting in increasing order of "from"
        // to order it by linear time
        vector<Trip> sortedTrips;
        for(auto trip : trips) {
            sortedTrips.push_back(Trip(trip[0], trip[1], trip[2]));
        }
        sort(sortedTrips.begin(), sortedTrips.end(), tripSort);

        // min heap according to "to" of a trip
        priority_queue<Trip, vector<Trip>, HeapCompare> ongoingTrips;

        int currPosition;
        int emptySlots = capacity;

        // simulation
        for(int i=0; i<sortedTrips.size(); i++) {

            Trip currTrip = sortedTrips[i];

            if(!ongoingTrips.empty()) {
                currPosition = min(currTrip.from, ongoingTrips.top().to);
            } else {
                currPosition = currTrip.from;
            }

            if(!ongoingTrips.empty() && currPosition == ongoingTrips.top().to) {
                while(!ongoingTrips.empty() && currPosition == ongoingTrips.top().to) {
                    emptySlots += ongoingTrips.top().passengers;
                    ongoingTrips.pop();
                }
                // revisit the currentTrip to sync time
                i--; 
                continue;
            }
            
            if(currTrip.passengers > emptySlots) return false;

            emptySlots -= currTrip.passengers;
            ongoingTrips.push(currTrip);
        }

        return true;

    }
};


// ************** LINEAR TRAVERSAL SOLUTION **************
class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> passengerChange(1001, 0);

        for(auto trip : trips) {
            int currPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            passengerChange[from] += currPassengers;
            passengerChange[to] -= currPassengers;
        }

        int currPassengers = 0;
        for(int passengers : passengerChange) {
            currPassengers += passengers;
            if(currPassengers > capacity) return false;
        }
        
        return true;
    }
};