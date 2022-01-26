/**************************************************************

STAIRCASE SEARCH

Given a M x N matrix which is row wise and column wise sorted.
You have to search the index of a given integer K in the matrix.

Input:
    arr = {
        {1, 4, 9},
        {2, 5, 10},
        {6, 7, 11}
    }
    key = 10

Output: 
    (1, 2)
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

pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    
    // m => rows
    // n => cols
    // start from top right corner
    int row = 0; // top row
    int col = n-1; // last column
    
    while(row < m && col >= 0) {
        if(k == v[row][col]) {
            return {row, col};
        } else if(k > v[row][col]) {
            row++;
        } else {
            col--;
        }
    }

    return {-1, -1};

}

// main function
int main() {

    vector<vector<int>> v{
        {1, 4, 9},
        {2, 5, 10},
        {6, 7, 11}
    };
    int k = 10;

    auto p = search(v.size(), v[0].size(), v, k);
    cout<<"\nPosition = ("<<p.first<<", "<<p.second<<")";
    
    
    return 0;

}