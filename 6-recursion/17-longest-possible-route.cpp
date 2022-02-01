/**************************************************************

LONGEST POSSIBLE ROUTE

Given an Mx N matrix, with a few hurdles arbitrarily placed,
calculate the length of longest possible route possible from 
top left position (0.0) to bottom right position (m.n) within 
the matrix. 
We are allowed to move to only adjacent cells which are not 
hurdles. The route cannot contains any diagonal moves and a 
location once visited in a particular path cannot be visited
again.

Input Format:
    In the function you are given number of rows M, number of 
    columns N and 2D vector (M X N) consisting of 0s and 1s 
    where 0s represents the hurdles.

Output Format:
    A single integer representing the length of longest path.

 
Input: 
    m = 3
    n = 3
    v = {1, 1, 1}
        {1, 1, 1}
        {0, 0, 1} 

Output:
    6

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

bool indexInBounds(int i, int j, int m, int n) {
    if(i >= 0 && i < m && j >= 0 && j < n) return true;
    return false;
}

void dfs(vector<vector<int>> v, int m, int n, int i, int j, int currSum, int &maxSum) {

    if(!indexInBounds(i, j, m, n)) return;

    if(i == m-1 && j == n-1) {
        maxSum = max(maxSum, currSum);
        return;
    }

    // can't be included in path, return
    if(v[i][j] == 0) return;

    // mark it as visited
    v[i][j] = 0;

    // up 
    dfs(v, m, n, i-1, j, currSum+1, maxSum);
    // down 
    dfs(v, m, n, i+1, j, currSum+1, maxSum);
    // left 
    dfs(v, m, n, i, j-1, currSum+1, maxSum);
    // right
    dfs(v, m, n, i, j+1, currSum+1, maxSum);

    // backtrack step
    v[i][j] = 1;

}

int findLongestPath(int m, int n, vector<vector<int>> v){
    int maxSum = 0;
    int i = 0;
    int j = 0;
    dfs(v, m, n, i, j, 0, maxSum);
    return maxSum;
}

// main function 
int main() {

    vector<vector<int>> v{
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 1}
    };
    int m = v.size();
    int n = v[0].size();

    int result = findLongestPath(m, n, v);
    cout<<"\nLongest path: "<<result;

    return 0;
    
}