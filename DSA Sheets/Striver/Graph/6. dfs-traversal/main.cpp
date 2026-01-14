#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(n) + recursion stack space: O(n), Time complexity: O(n) + O(2E)
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &df) {
	vis[node] = 1;
	df.push_back(node);

	for(auto it: adj[node]) {
		if(!vis[it]) {
			dfs(it, adj, vis, df);
		}
	}
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) {
	vector<int> vis(v, 0);
	int start = 0;
	vector<int> df;
	dfs(start, adj, vis, df);

	return df;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}