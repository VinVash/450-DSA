#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int>& stk, vector<int>& vis, vector<int> adj[]) {
	vis[node] = 1;
	for(auto it: adj[node]) {
		if(!vis[it]) {
			dfs(it, stk, vis, adj);
		}
	}

	stk.push(node);
}

void revDfs(int node, vector<int>& vis, vector<int> transpose[]) {
	cout << node << " ";
	vis[node] = 1;
	for(auto it: transpose[node]) {
		if(!vis[it]) {
			revDfs(it, vis, transpose);
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	stack<int> stk;
	vector<int> vis(n, 0);
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			dfs(i, stk, vis, adj);
		}
	}

	vector<int> transpose[n];
	for(int i = 0; i < n; i++) {
		vis[i] = 0; // mark every node vis as 0 again.
		for(auto it: adj[i]) {
			tranpose[it].push_back(i);
		}
	}

	while(!stk.empty()) {
		int node = stk.top();
		stk.pop();

		if(!vis[node]) {
			cout << "SCC: ";
			revDfs(node, vis, transpose);
			cout << endl;
		}
	}


	return 0;
}