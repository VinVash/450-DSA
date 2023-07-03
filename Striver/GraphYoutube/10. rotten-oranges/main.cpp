#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(N x M)
// Time complexity: O(N x M)
int orangesRotting(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else vis[i][j] = 0;
        }
    }
    
    int time = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]== 0 && grid[nrow][ncol] == 1){
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol] = 2;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
    }
    return time;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}