#include <bits/stdc++.h>
using namespace std;

// n nodes and n-1 edges is called a spanning tree.
// Time: O(N^2) where inner loop is running in array and O(NlogN) where inner loop is using priority queue.
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

	// create adjList
	unordered_map<int, list<pair<int, int>>> adj;

	for(int i=0; i < g.size(); i++) {
		int u = g[i].first.first;
		int v = g[i].first.second;
		int w = g[i].second;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	// Create the 3 data structures
	vector<int> key(n+1, INT_MAX);
	vector<bool> mst(n+1, false);
	vector<int> parent(n+1, -1);

	// main algo
	key[1] = 0;
	parent[1] = -1;

	for(int i = 1; i < n; i++) {
		int mini = INT_MAX;
		int u;

		for(int v=1; v <= n; v++) { // use priority queue here, for obtaining the lowest element in O(1) time.
			if(mst[v] == false && key[v] < mini) {
				u = v;
				mini = key[v];
			}
		}

		// mark min node as true
		mst[u] = true;

		// check its adjacent nodes
		for(auto it: adj[u]) {
			int v = it.first;
			int w = it.second;

			if(mst[v] == false && w < key[v]) {
				parent[v] = true;
				key[v] = w;
			}
		}
	}

	vector<pair<pair<int, int>, int>> res;

	for(int i = 2; i <= n; i++) {
		res.push_back(make_pair(make_pair(parent[i], i), key[i]));
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