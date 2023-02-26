/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // ******** for mins ********
    void dfsMins(int i, int sum, int currBits, int &maxBits, vector<string> &strs) {
        if(sum >= 60) return;
        if(currBits == maxBits) {
            string s = to_string(sum);
            if(s.length() == 1) s = "0" + s;
            strs.push_back(s);
            return;
        }
        if(i >= 60) return;
        dfsMins(i*2, sum, currBits, maxBits, strs); // dont include
        dfsMins(i*2, sum+i, currBits+1, maxBits, strs); // include
    }

    vector<string> generateMins(int bits) {
        if(bits == 0) return {"00"};
        if(bits >= 6) return {};

        vector<string> mins;
        dfsMins(1, 0, 0, bits, mins);

        return mins;
    }

    // ******** for hours ********
    void dfsHours(int i, int sum, int currBits, int &maxBits, vector<string> &strs) {
        if(sum >= 12) return;
        if(currBits == maxBits) {
            string s = to_string(sum);
            strs.push_back(s);
            return;
        }
        if(i >= 12) return;
        dfsHours(i*2, sum, currBits, maxBits, strs); // dont include
        dfsHours(i*2, sum+i, currBits+1, maxBits, strs); // include
    }

    vector<string> generateHours(int bits) {
        if(bits == 0) return {"0"};
        if(bits >= 4) return {};

        vector<string> hours;
        dfsHours(1, 0, 0, bits, hours);

        return hours;
    }

public:

    // ******** driver code ********
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string> result;
        
        for(int i=0; i<=turnedOn; i++) {

            vector<string> hours = generateHours(i);
            if(hours.size() == 0) continue;

            vector<string> mins = generateMins(turnedOn - i);
            if(mins.size() == 0) continue;
        
            for(string h : hours) {
                for(string m : mins) {
                    result.push_back(h + ":" + m);
                }
            }      
        }

        return result;
    }
};