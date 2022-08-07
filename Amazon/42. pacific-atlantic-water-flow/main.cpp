#include <bits/stdc++.h>
using namespace std;

bool safe(int i, int j, int N, int M)
{
    if (i < 0 || j < 0 || i >= N || j >= M)
        return false;
    return true;
}
 
// Function to perform a BFS
// Traversal and mark visited
void BFS(vector<vector<int> > matrix, int N, int M,
         queue<pair<int, int> > q,
         vector<vector<bool> >& vis)
{
    // Loop to traverse q
    while (q.empty() == false) {
        // Stores current coordinate
        pair<int, int> cur = q.front();
        q.pop();
 
        // Mark current visited
        vis[cur.first][cur.second] = true;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + x[i];
            int ny = cur.second + y[i];
 
            // If coordinate (nx, ny)
            // is inbound and rechable
            if (safe(nx, ny, N, M)
                && matrix[nx][ny]
                       >= matrix[cur.first]
                                [cur.second]
                && vis[nx][ny] == false) {
                // Insert into queue
                q.push({ nx, ny });
 
                // Mark visited
                vis[nx][ny] = true;
            }
        }
    }
}
 
// Function to find the count of
// valid coordinates
int countCoordinates(vector<vector<int> > mat,
                     int N, int M)
{
    // Queue to perform BFS
    queue<pair<int, int> > q1, q2;
 
    // Stores the visited coordinates
    // during the 1st traversal
    vector<vector<bool> > visited1(
        N,
        vector<bool>(M, false));
 
    // Stores the visited coordinates
    // during the 2nd traversal
    vector<vector<bool> > visited2(
        N,
        vector<bool>(M, false));
 
    // Insert the coordinates
    // directly connected
    for (int i = 0; i < M; i++) {
        q1.push({ 0, i });
        q2.push({ N - 1, i });
    }
    for (int j = 0; j < N - 1; j++) {
        q1.push({ j + 1, 0 });
        q2.push({ j, M - 1 });
    }
 
    // BFS for the 1st ocean
    BFS(mat, N, M, q1, visited1);
 
    // BFS for the 2nd ocean
    BFS(mat, N, M, q2, visited2);
 
    // Stores the required count
    int ans = 0;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // If coordinate (i, j)
            // is reachable from both
            if (visited1[i][j]
                && visited2[i][j]) {
                // Update count
                ans++;
            }
        }
    }
 
    // Return Answer
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int> > mat
        = { { 1, 2, 2, 3, 5 },
            { 3, 2, 3, 4, 4 },
            { 2, 4, 5, 3, 1 },
            { 6, 7, 1, 4, 5 },
            { 5, 1, 1, 2, 4 } };
 
    cout << countCoordinates(mat, mat.size(), mat[0].size());

	return 0;
}