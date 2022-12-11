/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    vector<pair<int, int>> sortedPosAndSpeed;
    int n = position.size();

    for(int i=0; i<n; i++) {
        sortedPosAndSpeed.push_back({position[i], speed[i]});
    }

    sort(sortedPosAndSpeed.begin(), sortedPosAndSpeed.end(), cmp);

    stack<pair<int, int>> s;
    s.push(sortedPosAndSpeed[n-1]);
    for(int i=n-2; i>=0; i--) {
        auto carBehind = sortedPosAndSpeed[i];
        float carBehindTime = (float) (target - carBehind.first) / (float) carBehind.second;

        auto carFront = s.top();
        float carFrontTime = (float) (target - carFront.first) / (float) carFront.second;

        // they form a fleet
        // don't push the behind car
        // onto the stack
        if(carBehindTime <= carFrontTime) { }

        // don't form a fleet
        else { 
            s.push(carBehind);
        }

    }

    return s.size();

}

int main() {

    return 0;
}