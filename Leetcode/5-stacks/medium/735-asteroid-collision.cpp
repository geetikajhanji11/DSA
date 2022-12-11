/*******************************************************************
class Solution {
public:

    class Asteroid {
        public:
        int weight;
        bool movingRight;

        Asteroid(int w) {
            this->weight = abs(w);
            this->movingRight = w > 0 ? true : false;
        }
    };

    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<Asteroid> s;
        for(int weight : asteroids) {
            Asteroid currAsteroid(weight);

            // top => left and curr_asteroid => right
            // OR
            // both top  and curr asteroid have same direction
            if(!s.empty() && ((!(s.top().movingRight) && currAsteroid.movingRight) || (s.top().movingRight == currAsteroid.movingRight))) {
                s.push(currAsteroid);
                continue;
            }

            // top => right and curr asteroid => left (3 cases)

            // CASE 1
            while(!s.empty() && (s.top().movingRight && !currAsteroid.movingRight) && (s.top().weight < currAsteroid.weight)) 
                s.pop();
                
            // CASE 2
            if(!s.empty() && (s.top().movingRight && !currAsteroid.movingRight) && (s.top().weight > currAsteroid.weight)) {
                continue;
            }

            // CASE 3
            if(!s.empty() && (s.top().movingRight && !currAsteroid.movingRight) && s.top().weight == currAsteroid.weight) {
                s.pop();
                continue;
            }

            s.push(currAsteroid);
            
        }

        vector<int> result(s.size());
        int i = s.size() - 1;
        while(!s.empty()) {
            int weight = s.top().weight;
            if(!(s.top().movingRight)) {
                weight = 0 - weight;
            }
            result[i] = weight;
            i--;
            s.pop();
        }
        return result;
    }
};
*******************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;

    for(int asteroid : asteroids) {

        // COLLISION CONDITION (+ve on top of -ve)
        // top => right 
        // asteroid => left
        while(!s.empty() && s.top() > 0 && asteroid < 0) {
            int diff = s.top() + asteroid;

            if(diff > 0) { // top > asteroid (asteroid destroy)
                asteroid = 0;
            } else if(diff < 0) { // top < asteroid (top destory)
                s.pop();
            } else { // top == asteroid (both destroy)
                s.pop();
                asteroid = 0;
            }
        }

        if(asteroid != 0) {
            s.push(asteroid);
        }
    }

    vector<int> result(s.size());
    int i = s.size() - 1;
    while(!s.empty()) {
        result[i] = s.top();
        s.pop();
        i--;
    }

    return result;
}

