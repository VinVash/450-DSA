#include <bits/stdc++.h>
using namespace std;

// Two ways to represent a graph in C++ :
// Adjacency matrix
// Adjacency list

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    // This is the adjacency list.
    int n, m;
	vector<int> adj[n+1];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	return 0;
}