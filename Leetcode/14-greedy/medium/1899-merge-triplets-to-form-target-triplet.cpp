/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<vector<int>> new_triplets;
    for(auto triplet : triplets) {
        bool valid = true;
        for(int i=0; i<3; i++) {
            if(triplet[i] > target[i]) {
                valid = false;
                break;
            } 
        }
        if(valid) new_triplets.push_back(triplet);
    }        

    bool first_found = false;
    bool second_found = false;
    bool third_found = false;

    for(auto triplet : new_triplets) {
        if(triplet[0] == target[0]) first_found = true;
        if(triplet[1] == target[1]) second_found = true;
        if(triplet[2] == target[2]) third_found = true;
    }

    return first_found && second_found && third_found;
}

int main() {

    return 0;
}