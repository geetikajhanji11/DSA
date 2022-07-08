/**************************************************************

https://www.youtube.com/watch?v=Y0lT9Fck7qI&t=882s&ab_channel=NeetCode

CLIMBING LADDER (3^n)

Given a ladder containing N steps, you can jump of 1, 2 or 3
at each step. Find the number of ways to climb the ladder.

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

int climbingLadder(int n) {
    
    // base case
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }

    // recursive case
    int ways1 = climbingLadder(n-1);
    int ways2 = climbingLadder(n-2);
    int ways3 = climbingLadder(n-3);

    return ways1 + ways2 + ways3;
}

// main function
int main() {

    int possibleWays = climbingLadder(4);
    cout<<possibleWays;
}




/********************* My solution

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

int climbingLadder(int n, int step, int ways) {
    
    // base case
    if(step > n) {
        return 0;
    }
    if(step == n) {
        return ways + 1;
    }

    // recursive case
    int ways1 = climbingLadder(n, step + 1, ways);
    int ways2 = climbingLadder(n, step + 2, ways);
    int ways3 = climbingLadder(n, step + 3, ways);

    return ways1 + ways2 + ways3;
}

// main function
int main() {

    int possibleWays = climbingLadder(4, 0, 0);
    cout<<possibleWays;
}

*/