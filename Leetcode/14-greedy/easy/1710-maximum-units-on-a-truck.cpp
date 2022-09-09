/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {

    static bool compare(vector<int> a, vector<int> b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);

        int units = 0;
        for(int i=0; i<boxTypes.size(); i++) {
            int boxes = boxTypes[i][0];
            int unitsPerBoxes = boxTypes[i][1];

            int x = min(boxes, truckSize);
            truckSize -= x;
            units += (x * unitsPerBoxes);

            if(truckSize == 0) break;

        }

        return units;
    }
};

// class Solution {

//     static bool compare(vector<int> a, vector<int> b) {
//         if(a[1] == b[1]) return a[0] < b[0];
//         return a[1] > b[1];
//     }

// public:
//     int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
//         sort(boxTypes.begin(), boxTypes.end(), compare);

//         int units = 0;
//         for(int i=0; i<boxTypes.size(); i++) {
//             int boxes = boxTypes[i][0];
//             int unitsPerBoxes = boxTypes[i][1];

//             if(boxes <= truckSize) {
//                 truckSize -= boxes;
//                 units += (boxes * unitsPerBoxes);
//             } else {
//                 units += (truckSize * unitsPerBoxes);
//                 truckSize = 0;
//                 break;
//             }
//         }

//         return units;
//     }
// };