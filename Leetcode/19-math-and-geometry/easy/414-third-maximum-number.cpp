/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        bool firstExists = false;
        bool secondExists = false;
        bool thirdExists = false;

        unordered_set<int> used;

        for(int num : nums) {

            if(used.find(num) != used.end()) continue;

            if(num > first) {

                
                used.erase(first);
                third = second;
                second = first;
                first = num;
                used.insert(first);

                if(secondExists) thirdExists = true;
                if(firstExists) secondExists = true;
                firstExists = true;

            } else if(num > second) {
                used.erase(second);
                third = second;
                second = num;
                used.insert(second);

                if(secondExists) thirdExists = true;
                secondExists = true;

            } else if(num > third) {
                used.erase(third);
                third = num;
                thirdExists = true;
                used.insert(third);
            }

            cout<<first<<", "<<second<<", "<<third<<endl;
        }

        if(thirdExists) return third;
        return first;
    }
};