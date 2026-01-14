#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

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

int maxRemove(vector<vector<int>>& stones, int n) {
	int maxRow = 0;
	int maxCol = 0;
	for(auto it: stones) {
		maxRow = max(maxRow, it[0]);
		maxCol = max(maxCol, it[1]);
	}

	DisjointSet ds(maxRow + maxCol + 1);

	unordered_map<int, int> stoneNodes;

	for(auto it: stones) {
		int nodeRow = it[0];
		int nodeCol = it[1] + maxRow + 1;

		ds.unionBySize(nodeRow, nodeCol);

		stoneNodes[nodeRow] = 1;
		stoneNodes[nodeCol] = 1;
	}

	int count = 0; // count the no. of bosses = components.
	for(auto it: stoneNodes) {
		if(ds.findUltimateParent(it.first) == it.first)
			count++;
	}

	return n - count;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}