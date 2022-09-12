/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> daysOfMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear(int year) {
        return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    }

    int dayOfYear(int year, int month, int day) {
        if(isLeapYear(year)) daysOfMonth[2] = 29;
        
        int totalDays = 0;
        for(int m=1; m<month; m++) {
            totalDays += daysOfMonth[m];
        }
        totalDays += day;

        // make feb back as 28
        daysOfMonth[2] = 28; 
        return totalDays;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        string smallerDate = date1 <= date2 ? date1 : date2; 
        string biggerDate = date1 >= date2 ? date1 : date2;

        // get smaller date
        int year1 = stoi(smallerDate.substr(0, 4));
        int month1 = stoi(smallerDate.substr(5, 2));
        int day1 = stoi(smallerDate.substr(8, 2));

        // get bigger date
        int year2 = stoi(biggerDate.substr(0, 4));
        int month2 = stoi(biggerDate.substr(5, 2));
        int day2 = stoi(biggerDate.substr(8, 2));
        
        if(year1 == year2) {
            return dayOfYear(year2, month2, day2) - dayOfYear(year1, month1, day1);
        }

        // get the day of the year from the bigger date
        int daysAfter = dayOfYear(year2, month2, day2);

        // get days of years (year1, year2) [non - inclusive]
        int daysBetween = 0;
        for(int year=year1+1; year<year2; year++) {
            if(isLeapYear(year)) {
                daysBetween += 366;
            } else {
                daysBetween += 365;
            }
        }

        // get the day of year from the smaller date
        // and subtract from the total days of that year
        int daysBefore = (isLeapYear(year1) ? 366 : 365) - dayOfYear(year1, month1, day1);

        // return sum
        return daysBefore + daysBetween + daysAfter;
    }
};