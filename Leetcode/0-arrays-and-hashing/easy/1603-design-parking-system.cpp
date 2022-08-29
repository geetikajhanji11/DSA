/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ParkingSystem {
    unordered_map<int, int> emptySlots;

public:
    ParkingSystem(int big, int medium, int small) {
        emptySlots.insert({1, big});
        emptySlots.insert({2, medium});
        emptySlots.insert({3, small});
    }
    
    bool addCar(int carType) {
        if(emptySlots[carType] > 0) {
            emptySlots[carType]--;
            return true;
        }
        return false;
    }
};