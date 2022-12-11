/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isRobotBounded(string instructions) {

        // DIRECTION (NORTH)
        int dirX = 0;
        int dirY = 1;

        // POSITION
        int x = 0;
        int y = 0;

        for(char instruction : instructions) {

            if(instruction == 'L') {
                int temp_dirX = dirX;
                int temp_dirY = dirY;
                dirX = (-1) * temp_dirY;
                dirY = temp_dirX;
            } 
            
            else if(instruction == 'R') {
                int temp_dirX = dirX;
                int temp_dirY = dirY;
                dirX = temp_dirY;
                dirY = (-1) * temp_dirX;
            } 
            
            else {
                x += dirX;
                y += dirY;
            }
        }

        bool samePosition = (x == 0) && (y == 0);
        bool sameDirection = (dirX == 0) && (dirY == 1);
        
        return samePosition || !sameDirection;
    }
};