/*******************************************************************
FOLLOW - UP ANSWER

Two one-dimensional arrays "times" and "hits" with a size of 300 are 
defined, which are used to store timestamps and hits respectively.

In the click function, take the time stamp to 300, 
and then check whether the previously saved time stamp 
in this position is the same as the current time stamp. 
It also means that it is the same time stamp, then the 
corresponding number of clicks will increase by 1, 
if not the same, it means that five minutes have passed, 
then reset the corresponding number of clicks to 1.

Then when returning the number of hits, we need to traverse 
the times array to find all the positions within 5 minutes, 
and then add up the number of clicks in the corresponding 
positions in hits.

* real-time getHits() ?
* batch off-line process, then getHits() ?

1st thought is map reduce, distribute to multiple hosts, 
so when getHits() need a broadcast to collect all data

options: 
    1.  use a lock 
    2.  equal distribution each machine works independently 
        to count its own users from the past minute. 
        When we request the global number, we just need to 
        add all counters together.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** MAIN QUESTION ***********
class HitCounter {
    queue<int> q; // stores timestamps

public:

    // constructor
    HitCounter() {}

    // O(1)
    void hit(int timestamp) {
        q.push(timestamp);
    }

    // O(n)
    int getHits(int timestamp) {
        int startTime = max(0, timestamp - 300);

        // remove all hits over 300 seconds old
        while(!q.empty() && q.front() <= startTime) {
            q.pop();
        }

        return q.size();
    }
};


// *********** FOLLOW-UP QUESTION ***********
// What if the number of hits per second could be very large? 
// Does your design scale?

class HitCounter {
    
    vector<int> timestamps;
    vector<int> hits;

public:

    // constructor
    HitCounter() {
        timestamps = vector<int>(300, 0);
        hits = vector<int>(300, 0);
    }

    // O(1)
    void hit(int timestamp) {
        int idx = timestamp % 300;

        if(timestamps[idx] == timestamp) {
            hits[idx]++;
        } else {
            timestamps[idx] = timestamp;
            hits[idx] = 1;
        }
    }

    // O(n)
    int getHits(int timestamp) {
        
        int totalHits = 0;

        for(int i=0; i<300; i++) {
            if(timestamp - timestamps[i] < 300) {
                totalHits += hits[i];
            }
        }

        return totalHits;
    }
};

int main() {

    return 0;
}