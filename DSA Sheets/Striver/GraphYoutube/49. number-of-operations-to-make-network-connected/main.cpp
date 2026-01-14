#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(4 * ⍺ * no_of_connections)

class DisjointSet {
public:
	vector<int> rank, parent, size;

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

int solve(int n, vector<vector<int>>& edges) {
	DisjointSet ds(n);

	int countExtras = 0;
	for(auto it: edges) {
		int u = it[0];
		int v = it[1];

		if(ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
			countExtras++;
		} else {
			ds.unionBySize(u, v);
		}
	}

	int countComponents = 0;

	for(int i = 0; i < n; i++) {
		if(ds.parent[i] == i)
			countComponents++;
	}

	int ans = countComponents-1;
	if(countExtras >= ans)
		return ans;
	return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}