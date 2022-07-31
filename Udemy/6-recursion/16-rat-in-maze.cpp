/**************************************************************

RAT IN A MAZE


You are given a an integer N and a grid of size NxN. 
The cells of the grid are numbered row wise from 1 to NA2. 
Rat wants to travel from cell number 1 to cell number N42, 
and it can move in only right direction or down direction 
from a particular cell. There is exactly one path from source
to destination as some cells are blocked. Help the rat to find 
the path.

Input Format:
    In the function an integer N is given, and a 2D vector 
    consisting of only ‘O's And ‘Y's is given where X' 
    represents blocked cell.

Output Format:
    Return a vector of cell numbers of cells in path (in sequence).

Input:
    4
    {'O', 'O', 'X', 'O'}
    {'O', 'X', 'O', 'O'}
    {'O', 'O', 'O', 'X'}
    {'X', 'X', 'O', 'O'}

Output: 
    [1, 5, 9, 10, 11, 15, 16]
    

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


// *************************************************************
bool in_bounds(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool dfs(int i, int j, vector<vector<char>> &c, vector<vector<int>> &value, vector<int> &result, int &n) {

    if(!in_bounds(i, j, n)) return false;
    if(c[i][j] == 'X') return false;

    if(i == n-1 && j == n-1) {
        result.push_back(value[i][j]);
        return true;
    }
    
    // moves right
    if(dfs(i, j+1, c, value, result, n)) {
        result.push_back(value[i][j]);
        return true;
    }

    // moves down
    if(dfs(i+1, j, c, value, result, n)) {
        result.push_back(value[i][j]);
        return true;
    }

    return false;

}

vector<int> findPath(int n, vector<vector<char>> c) {
    vector<vector<int>> value;
    int ctr = 1;
    for(int i=0; i<n; i++) {
        vector<int> row;
        for(int j=0; j<n; j++) {
            row.push_back(ctr);
            ctr++;
        }
        value.push_back(row);
    }

    vector<int> result;
    dfs(0, 0, c, value, result, n);
    reverse(result.begin(), result.end());

    return result;
   
}
// *************************************************************

bool indexInBounds(int i, int j, int n) {
    if(i >= 0 && i < n && j >= 0 && j < n) return true;
    return false;
}

void dfs(int n, vector<vector<char>> c, int i, int j, vector<vector<int>> &val, vector<int> path, int dest) {

    if(!indexInBounds(i, j, n)) return;

    if(val[i][j] == n * n) {
        path.push_back(dest);
        for(int pos : path) {
            cout<<pos<<" ";
        }
        return;
    }

    if(c[i][j] == 'X') return;

    c[i][j] = 'X';
    path.push_back(val[i][j]);

    // up 
    dfs(n, c, i-1, j, val, path, dest);
    // down 
    dfs(n, c, i+1, j, val, path, dest);
    // left 
    dfs(n, c, i, j-1, val, path, dest);
    // right
    dfs(n, c, i, j+1, val, path, dest);

    path.pop_back();
    c[i][j] = 'O';

}

vector<int> findPath(int n, vector<vector<char>> c) {

    vector<vector<int>> val(n, vector<int>(n, 0));
    vector<int> path;
    int dest = n * n;

    int num = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            val[i][j] = num;
            num++;
        }
    }

    dfs(n, c, 0, 0, val, path, dest);

    return path;
}

// main function 
int main() {

    vector<vector<char>> c{
        {'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O'},
    };
    int n = c.size();

    vector<int> result = findPath(n, c);
    
    return 0;
    
}