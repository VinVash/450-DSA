#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time Complexity: O(ElogV)
// Here E = n*m*4, and V = n*m
// Therefore, time complexity: n*m*4 * log(n*m)
// Space complexity: O(n*m)

int MinimumEffort(vector<vector<int>>& heights) {
    
    // { diff, { row, col } }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    int n = heights.size();
    int m = heights[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    
    dist[0][0] = 0;
    pq.push({ 0, {0, 0}});
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        
        if(row == n-1 && col == m-1)
            return diff;
        
        for(int i = 0; i < 4; i++) {
            int newr = row + dr[i];
            int newc = col + dc[i];
            
            if(newr >= 0 && newc >= 0 && newr < n && newc < m) {
                int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                
                if(newEffort < dist[newr][newc]) {
                    dist[newr][newc] = newEffort;
                    pq.push({ newEffort, { newr, newc } });
                }
            }
        }
    }
    
    return 0; // unreachable.
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}