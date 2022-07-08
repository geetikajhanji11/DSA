/*******************************************************************
 * GRAPH SEQUENCE
 * 
 * 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cellInBounds(int i, int j, int rows, int cols) {
    if(i >= 0 && i < rows && j >= 0 && j < cols) return true;
    return false;
}

// int dfs(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &dp) {

//     int curr_cell = matrix[i][j];
//     cout<<curr_cell<<endl;
//     if(dp[i][j] != -1) return dp[i][j];

//     // 4 directions => up, down, left, right
//     vector<int> dx = {-1, 1, 0, 0};
//     vector<int> dy = {0, 0, -1, 1};

//     int size = 1;
//     int max_size = size;
//     for(int k=0; k<4; k++) {
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         if(!cellInBounds(next_i, next_j, matrix.size(), matrix[0].size())) continue;
        
//         if(matrix[next_i][next_j] > curr_cell) {

//         }
//         size += dfs(matrix, next_i, next_j, dp);
//         dp[next_i][next_j] = size;
//         max_size = max(max_size, size);
//     }

    
//     return size;
// }


// int longestPathSequence(vector<vector<int> > matrix){
    
//     int max_size = 0;
//     int rows = matrix.size();
//     int cols = matrix[0].size();

//     vector<vector<int> > dp(rows, vector<int>(cols, -1));
//     for(int i=0; i<matrix.size(); i++) {
//         for(int j=0; j<matrix[0].size(); j++) {
//             // cout<<"\n"<<matrix[i][j]<<" = ";
//             int curr_size = dfs(matrix, i, j, dp);
//             cout<<curr_size;
//             max_size = max(max_size, curr_size);
//         }
//     }

//     return max_size;
    
// }


void dfs(
    vector<vector<int>> matrix, 
    vector<vector<bool> > &visited, 
    vector<vector<int> > &cache, 
    int i, int j, int m, int n) {
	
    // mark cell as visited
	visited[i][j] = 1;
	
    // directions
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,1,-1};
	
	int cnt = 0;
	for(int k=0; k<4; k++){
		int nx = i + dx[k];
		int ny = j + dy[k];
		
		if(cellInBounds(nx, ny, m, n) && matrix[nx][ny] > matrix[i][j]) {
			int subProblemCnt = 0;
			if(visited[nx][ny]){
				cnt = max(cnt, 1+cache[nx][ny]);
			}
			else{
				dfs(matrix,visited,cache,nx,ny,m,n);
				cnt = max(cnt,1+cache[nx][ny]);	
			}
		}
	}
	cache[i][j] = cnt;
	return;
}

int longestPathSequence(vector<vector<int>> matrix) {
  // Write your code here.
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<bool> > visited(m+1,vector<bool>(n+1,0));
	vector<vector<int> > cache(m+1,vector<int>(n+1,0));
	//do a dfs from every cell 
    //and store the length of of maximum len seq startinf from that cell
	int ans = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dfs(matrix,visited,cache,i,j,m,n);
			ans = max(ans,cache[i][j]);
		}
	}
	return ans+1;
};

int main() {

    vector<vector<int> > matrix = {
        {0, 2, 4, 3, 2},
        {7, 6, 5, 5, 1},
        {8, 9, 7, 18, 14},
        {5, 10, 11, 12, 13}
    };

    int result = longestPathSequence(matrix);
    cout<<result;

    return 0;
}