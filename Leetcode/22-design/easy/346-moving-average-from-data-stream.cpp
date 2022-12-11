/*******************************************************************
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]

Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MovingAverage {
    int size;

    queue<int> q;
    int sum;

public:
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }

    double next(int val) {
        sum += val;
        q.push(val);

        if(q.size() > size) {
            sum -= q.front();
            q.pop();
        }

        return (double) sum / q.size();
    }
 
};
 
int main() {

    MovingAverage MA(3);

    vector<int> nums = {1, 10, 3, 5};

    for(int num : nums) {
        cout<<MA.next(num)<<endl;
    }
    return 0;
}