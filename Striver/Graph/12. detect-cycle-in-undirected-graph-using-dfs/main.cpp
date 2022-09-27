#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(N) -> recursion stack space + O(N) -> visited array = O(N).
// Time complexity: O(N) + o(N + 2E)
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
	vis[node] = 1;
	for(auto adjacentNode: adj[node]) {
		if(!vis[adjacentNode]) {
			if(dfs(adjacentNode, node, vis, adj) == true)
				return true;
		} else if(adjacentNode != parent) {
			return true;
		}
	}

	return false;
}

bool isCycle(int V, vector<int> adj[]) {
	int vis[V] = {0};

	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			if(dfs(i, -1, vis, adj) == true)
				return true;
		}
	}

	return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}