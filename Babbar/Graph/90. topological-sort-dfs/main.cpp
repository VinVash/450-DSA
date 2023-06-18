#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &stk, unordered_map<int, list<int>> &adj) {
	visited[node] = true;

	for(auto neighbour: adj[node]) {
		if(!visited[neighbour]) {
			dfs(neighbour, visited, stk, adj);
		}
	}

	// main step in topological ordering.
	stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
	
	// create adjlist
	unordered_map<int, list<int>> adj;

	for(int i=0; i < e; i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// call dfs topological sort util function for all components.
	vector<bool> visited(v);
	stack<int> stk;
	for(int i = 0; i < v; i++) {
		if(!visited[i]) {
			dfs(i, visited, stk, adj);
		}
	}

	vector<int> ans;
	while(!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}
	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}