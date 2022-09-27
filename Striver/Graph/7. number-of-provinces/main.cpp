#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLs[], int vis[]) {
	vis[node] = 1;
	for(auto it: adjLs[node]) {
		if(!vis[it]) {
			dfs(it, adjLs, vis);
		}
	}
}

// Time complexity: O(N) + O(V + 2E)
int numProvinces(vector<vector<int>> adj, int V) {
	vector<int> adjLs[V];

	// to change adjacency matrix to list.
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(adj[i][j] == 1 && i != j) {
				adjLs[i].push_back(j);
				adjLs[j].push_back(i);
			}
		}
	}

	int vis[V];
	memset(vis, 0, sizeof(vis));
	int res = 0;
	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			res++;
			dfs(i, adjLs, vis);
		}
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}