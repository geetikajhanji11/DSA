/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SeatManager {
    int n;
    priority_queue<int, vector<int>, greater<int>> freeSeats;

public:
    SeatManager(int n) {
        this->n = n;
        for(int i=1; i<=n; i++) {
            this->freeSeats.push(i);
        }
    }
    
    int reserve() {
        int seat = freeSeats.top();
        freeSeats.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        freeSeats.push(seatNumber);
    }
};

int main() {

    return 0;
}