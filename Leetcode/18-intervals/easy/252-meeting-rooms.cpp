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

struct compare{
    inline bool operator() (const Interval& i1, const Interval& i2) {
        if(i1.start == i2.start) return i1.end < i2.end;
        return (i1.start < i2.start);
    }
};

bool canAttendMeetings(vector<Interval> &intervals) {

    if(intervals.size() == 0) return true;

    sort(intervals.begin(), intervals.end(), compare());

    int prev_start = intervals[0].start;
    int prev_end = intervals[0].end;
    for(int i=1; i<intervals.size(); i++) {

        int curr_start = intervals[i].start;
        int curr_end = intervals[i].end;

        if(prev_start <= curr_start && curr_start < prev_end) return false;

        prev_start = curr_start;
        prev_end = curr_end;
    }

    return true;

}

int main() {

    vector<Interval> intervals;
    Interval i1(5, 8);
    intervals.push_back(i1);
    Interval i2(9, 15);
    intervals.push_back(i2);

    if(canAttendMeetings(intervals)) cout<<"\ntrue";
    else cout<<"\nfalse";
    return 0;
}