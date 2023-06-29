#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Space complexity: O(V + 2E) + O(3N)
// Time complexity: O(V + 2E)

int timer = 0;

void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {
	vis[node] = 1;
	tin[node] = low[node] = timer;
	timer++;

	for(auto it: adj[node]) {
		if(it == parent) continue;
		if(vis[it] == 0) {
			dfs(it, node, vis, adj, tin, low, bridges);
			low[node] = min(low[node], low[it]);

			// checking node ------- it
			if(low[it] > tin[node]) {
				bridges.push_back({ it, node });
			}

		} else {
			low[node] = min(low[node], low[it]);
		}
	}
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	vector<int> adj[n];

	for(auto it: connections) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	vector<int> vis(n, 0);
	int tin[n];
	int low[n];
	vector<vectorint>> bridges;

	dfs(0, -1, vis, adj, tin, low, bridges);

	return bridges;

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}