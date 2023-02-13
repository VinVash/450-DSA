#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
	color[node] = col;

	for(auto adjNode: adj[node]) {
		if(color[adjNode] == -1) {
			if(dfs(adjNode, !col, color, adj) == false)
				return false;
		} else if(color[adjNode] == col) {
			return false;
		}
	}

	return true;
}

bool isBipartite(int V, vector<int> adj[]) {
	vector<int> color(V, -1);

	for(int i = 0; i < V; i++) {
		if(color[i] == -1) {
			if(dfs(i, 0, color, adj) == false)
				return false;
		}
	}

	return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}