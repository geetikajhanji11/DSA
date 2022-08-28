/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        while(left <= right) {

            // only 1 heavy person
            if(people[right] == limit || (people[left] + people[right] > limit)) {
                right--;
            }

            // 2 people
            else if(people[left] + people[right] <= limit) {
                left++;
                right--;
            }

            // increase number of boats
            boats++;
        }

        return boats;
    }
};