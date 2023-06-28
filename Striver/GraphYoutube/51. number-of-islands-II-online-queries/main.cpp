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

bool isValid(int r, int c, int n, int m) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

vector<int> numberOfIslands(int n, int m, vector<vector<int>>& operators) {
	DisjointSet ds(n * m);
	int vis[n][m];
	memset(vis, 0, sizeof vis);

	int count = 0;
	vector<int> ans;
	for(auto it: operators) {
		int row = it[0];
		int col = it[1];
		if(vis[row][col] == 1) { // already an island.
			ans.push_back(count);
		} else {
			vis[row][col] = 1;
			count++;

			int dr[] = {-1, 0, 1, 0};
			int dc[] = {0, 1, 0, -1};

			for(int idx = 0; idx < 4; idx++) {
				int adjr = row + dr[idx];
				int adjc = col + dc[idx];

				if(isValid(adjr, adjc, n, m)) {
					if(vis[adjr][adjc] == 1) {
						int nodeNo = row * m + col;
						int adjNodeNo = adjr * m + adjc;

						if(ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo)) {
							count--; // joining two islands.
							ds.unionBySize(nodeNo, adjNodeNo);
						}
					}
				}
			}

			ans.push_back(count);
		}

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