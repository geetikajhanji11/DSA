/*******************************************************************
Gas stations along circular route, return where to start to complete 
1 trip
Ex. gas = [1,2,3,4,5] cost = [3,4,5,1,2] -> index 3 (station 4), tank = 4,8,7,6,5

At a start station, if total ever becomes negative won't work, try next station

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas = accumulate(gas.begin(), gas.end(), 0);
    int total_cost = accumulate(cost.begin(), cost.end(), 0);

    if(total_gas < total_cost) return -1;

    int total = 0;
    int start_index = 0;

    for(int i=0; i<gas.size(); i++) {
        int diff = gas[i] - cost[i];
        total += diff;

        if(total < 0) {
            total = 0;
            start_index = i + 1;
        }
    }

    return start_index;
}

int main() {

    return 0;
}