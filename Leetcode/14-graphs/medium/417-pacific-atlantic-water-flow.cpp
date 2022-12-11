#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

bool in_bounds(int i, int j, vector<vector<int>>& grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

void can_reach_pacific(int i, int j, set<pair<int, int>> &pacific, vector<vector<int>> &visited_pacific, vector<vector<int>>& heights) {

    visited_pacific[i][j] = true;
    pacific.insert({i, j});
    
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];

        if(!in_bounds(next_i, next_j, heights)) continue;

        if(!visited_pacific[next_i][next_j] && 
            (heights[next_i][next_j] >= heights[i][j] || next_i == 0 || next_j == 0)) {
                can_reach_pacific(next_i, next_j, pacific, visited_pacific, heights);
        }
    }

}


void can_reach_atlantic(int i, int j, set<pair<int, int>> &atlantic, vector<vector<int>> &visited_pacific, vector<vector<int>>& heights) {

    visited_pacific[i][j] = true;
    atlantic.insert({i, j});
    
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];

        if(!in_bounds(next_i, next_j, heights)) continue;

        if(!visited_pacific[next_i][next_j] && 
            (heights[next_i][next_j] >= heights[i][j] || next_i == heights.size()-1 || next_j == heights[0].size()-1)) {
                can_reach_atlantic(next_i, next_j, atlantic, visited_pacific, heights);
        }
    }

}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    int rows = heights.size();
    int cols = heights[0].size();

    // for pacific
    set<pair<int, int>> pacific;
    vector<vector<int>> visited_pacific(rows, vector<int>(cols, 0));
    can_reach_pacific(0, 0, pacific, visited_pacific, heights);

    // for atlantic
    set<pair<int, int>> atlantic;
    vector<vector<int>> visited_atlantic(rows, vector<int>(cols, 0));
    can_reach_atlantic(heights.size()-1, heights[0].size()-1, atlantic, visited_atlantic, heights);

    // taking the common pairs as ans
    vector<vector<int>> result;
    for(auto p : pacific) {
        if(atlantic.find(p) != atlantic.end()) {
            vector<int> common_pair;
            common_pair.push_back(p.first);
            common_pair.push_back(p.second);
            result.push_back(common_pair);
        }
    }

    return result;
}

int main() {

    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    auto res = pacificAtlantic(heights);

    for(auto v : res) {
        for(int num : v) cout<<num<<", ";
        cout<<endl;
    }

    return 0;
}