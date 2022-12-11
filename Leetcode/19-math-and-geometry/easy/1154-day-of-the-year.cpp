/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    vector<int> daysOfMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    bool isLeapYear(int year) {
        return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    }


    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        daysOfMonth[2] = isLeapYear(year) ? 29 : 28;

        int totalDays = 0;
        for(int m=1; m<month; m++) {
            totalDays += daysOfMonth[m];
        }
        totalDays += day;

        return totalDays;
    }
};