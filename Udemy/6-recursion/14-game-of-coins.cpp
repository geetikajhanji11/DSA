/**************************************************************

GAME OF COINS (DONT UNDERSTAND YET)

Oswald and Henry are playing the game of coins. 
They have a row of 'n’ coins [C1.C2.C3..Cn] with values 
[V1.V2.V3..Vn] where Ci coin has Vi value. They take turns 
alternatively. In one turn the player can pick either the 
first or the last coin of the row. Given both Oswald and Henry 
are very smart players, you need to find the maximum possible 
value Oswald can earn if he plays first.

Input Format:
    In the function you are given an integer N i.e, 
    the number of coins and a vector V which represents 
    the values of each coin in the row respectively.

Output Format:
    Return a single integer which is the maximum possible value 
    as asked in the question.

Constraints:
    1 <= N <= 15
    1 <= V[i] <= 1000
    
    
Input:
    4
    1 2 3 4

Output:
    6

Explanation:
    Oswald will pick up coin with value 4, Henry will pick coin 
    with value 3, Oswald will pick 2 and
    Henry will pick 1. Hence 4 + 2 = 6.

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
#include <set>
using namespace std;

// ***********************************
int pick_max(int left, int right, vector<int> &v) {

    if(left == right || left + 1 == right) {
        return max(v[left], v[right]);
    }

    // OSWALD PICKS LEFT
    // (henry can pick either left or right)
    // we have to minimize oswald's answer since henry picks max too
    int henry_picks_left = pick_max(left+2, right, v);
    int henry_picks_right = pick_max(left+1, right-1, v);
    int oswald_picks_left = v[left] + min(henry_picks_left, henry_picks_right);

    // OSWALD PICKS RIGHT
    // (henry can pick either left or right)
    // we have to minimize oswald's answer since henry picks max too
    henry_picks_left = pick_max(left+1, right-1, v);
    henry_picks_right = pick_max(left, right-2, v);
    int oswald_picks_right = v[right] + min(henry_picks_left, henry_picks_right);

    return max(oswald_picks_left, oswald_picks_right);
}

int MaxValue(int n, vector<int> v){
    int ans = pick_max(0, n-1, v);
    return ans;
}


// ***********************************
int game(vector<int> v, int left, int right){

    // if there is 1 or 2 elements in subarray
    // from left to right
    if(left == right || left == right-1){
        return max(v[left], v[right]);
    }

    int m1 = min(game(v, left+2, right), game(v, left+1, right-1));

    int m2 = min(game(v, left+1, right-1), game(v, left, right-2));

    int op1 = v[left] + m1;
    int op2 = v[right] + m2; 
    
    return max(op1, op2); 
}

int MaxValue(int n, vector<int> v){
    int res = game(v, 0, n-1);
    return res;
}

// main function 
int main() {

    vector<int> v{1, 5, 2};
    
    cout<<MaxValue(3, v);
    return 0;
    
}