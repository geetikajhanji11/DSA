#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool in_bounds(int i, int j, vector<vector<int>>& image) {
    return i >= 0 && i < image.size() && j >= 0 && j < image[0].size();
}

void dfs(int i, int j, vector<vector<int>>& image, int src_colour, int target_color) {
    if(!in_bounds(i, j, image)) return;
    if(image[i][j] != src_colour) return;

    image[i][j] = target_color;

    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        dfs(next_i, next_j, image, src_colour, target_color);
    }

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) return image;
    dfs(sr, sc, image, image[sr][sc], color);
    return image;
}

int main() {

    return 0;
}