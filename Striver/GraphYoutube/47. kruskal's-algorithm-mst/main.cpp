#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;


class DisjointSet {
	vector<int> rank, parent, size;
public:
	DisjointSet(int n) {
		rank.resize(n+1, 0);
		parent.resize(n+1, 0);
		size.resize(n+1, 0);
		for(int i = 0; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findUltimateParent(int node) {
		if(node == parent[node])
			return node;
		return parent[node] = findUltimateParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);

		if(ulp_u == ulp_v)
			return;
		if(rank[ulp_u] < rank[ulp_v])
			parent[ulp_u] = ulp_v;
		else if(rank[ulp_v] < rank[ulp_u])
			parent[ulp_v] = ulp_u;
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}

	void unionBySize(int u, int v) {
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);

		if(ulp_u == ulp_v)
			return;

		if(size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		} else {
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}



	}
};

// Suppose edge 1 ----- 2, with weight  = 5
// 1 -> (2, 5)
// 2 -> (1, 5)
int spanningTree(int V, vector<vector<int>> adj[]) {

	// O(M)
	vector<pair<int, pair<int, int>>> edges;

	// O(V + E)
	for(int i = 0; i < V; i++) {
		for(auto it: adj[i]) {
			int adjNode = it[0];
			int wt = it[1];
			int node = i;

			edges.push_back({ wt, { node, adjNode }});
		}
	}

	DisjointSet ds(V);

	// MlogM for sorting
	sort(edges.begin(), edges.end());
	int mstWt = 0;

	// M * 4 * ⍺ * 2
	for(auto it: edges) {
		int wt = it.first;
		int u = it.second.second;
		int v = it.second.first;

		if(ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
			mstWt += wt;
			ds.unionBySize(u, v);
		}

	}

	return mstWt;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}