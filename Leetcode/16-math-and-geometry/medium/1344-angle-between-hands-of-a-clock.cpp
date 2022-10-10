/*******************************************************************
12 hours = 360 deg
1 hour  = (360 / 12) deg 
        = 30 deg
60 mins = 30 deg
1 min   = (30 / 60) deg
        = 0.5 deg
------------------------------
So, we see (from the top of clock, i.e., at 12)
 * 1 hour = 30 deg
 * 1 min = 0.5 deg
------------------------------

Now, given "hour" and "minutes"

1. Angle 1

    =>  We first find how far the given hour is from the starting point.
        This is achieved by doing:
            x = hour * 30

    =>  Now we find how farther this hour hand actually is with the help
        of "minutes", because if time is something like 6:45, the hour hand
        is not exactly at 6, it is somewhere between 6 and 7. This somewhere
        between is calculated as:
            y = minutes * 0.5

    =>  angle1 = x + y

2. Angle 2

    =>  We first find the pseudo hour, which is the hour at which the
        minute hand is pointing at. This is calculated as:
            pseudoHour = minutes / 5.0;

    =>  Now we find how far from the starting point is this psedudoHour

    =>  angle2 = pseudoHour * 30.0


*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        // angle 1
        double x = hour * 30;
        double y = minutes * 0.5;
        double angle1 = x + y;

        // angle 2
        double pseudoHour = minutes / 5.0;
        double angle2 = pseudoHour * 30.0;

        // get two final angles
        double op1 = abs(angle1 - angle2);
        double op2 = 360 - op1;

        return min(op1, op2);
    }
};