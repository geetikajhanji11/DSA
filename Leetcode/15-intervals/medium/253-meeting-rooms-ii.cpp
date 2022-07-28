/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

int minMeetingRooms(vector<Interval> &intervals) {
    int n = intervals.size();

    vector<int> start;
    vector<int> end;

    for(auto interval : intervals) {
        start.push_back(interval.start);
        end.push_back(interval.end);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0;
    int j = 0;

    int rooms = 0;
    int count = 0;
    
    while(i < n) {

        if(start[i] < end[j]) {
            count++;
            i++;
        }

        else if(start[i] > end[j]) {
            count--;
            j++;
        }

        else if(start[i] == end[j]) { // end room first
            count--;
            j++;
        }

        rooms = max(rooms, count);
    }

    return rooms;
}

int main() {

    // [(0,30),(5,10),(15,20),(12,20),(30,40),(35,50)]
    vector<Interval> intervals;
    Interval i1(0, 30);
    intervals.push_back(i1);
    Interval i2(5, 10);
    intervals.push_back(i2);
    Interval i3(15, 20);
    intervals.push_back(i3);
    Interval i4(12, 20);
    intervals.push_back(i4);
    Interval i5(30, 40);
    intervals.push_back(i5);
    Interval i6(35, 50);
    intervals.push_back(i6);

    int ans = minMeetingRooms(intervals);
    cout<<"\nans = "<<ans;
    return 0;
}