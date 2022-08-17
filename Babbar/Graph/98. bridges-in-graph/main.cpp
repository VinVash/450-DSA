#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
	vis[node] = true;
	disc[node] = low[node] = timer++;

	for(auto nbr: adj[node]) {
		if(nbr == parent)
			continue;
		if(!vis[node]) {
			dfs(nbr, node, timer, disc, low, result, adj, vis);
			low[node] = min(low[node], low[nbr]);

			// check edge is bridge.
			if(low[nbr] > disc[node]) {
				vector<int> res;
				res.push_back(node);
				res.push_back(nbr);
				result.push_back(res);
			}

		} else {
			// node already visited and not parent
			// back edge
			low[node] = min(low[node], disc[nbr]);
		}
	}
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
	// adjList
	unordered_map<int, list<int>> adj;

	for(int i=0; i < edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int timer = 0;
	vector<int> disc(v, -1);
	vector<int> low(v, -1);
	int parent = -1;
	unordered_map<int, bool> vis;

	vector<vector<int>> result;
	// dfs
	for(int i = 0; i < v; i++) { // for covering all components
		if(!vis[i]) {
			dfs(i, parent, timer, disc, low, result, adj, vis);
		}
	}

	return result;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}

// Time complexity:
// 		Since the main step is DFS, therefore time = O(N+E) = O(V+E)
// 
// Space complexity:
// 		O(N) = Linear
