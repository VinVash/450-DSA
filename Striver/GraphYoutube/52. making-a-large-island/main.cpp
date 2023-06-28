#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(N^2 * r) r=4 directions: for which dr and dc is used.

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

bool isValid(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int MaxConnection(vector<vector<int>>& grid) {
    int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);
    // step - 1
    for (int row = 0; row < n ; row++) {
        for (int col = 0; col < n ; col++) {
            if (grid[row][col] == 0) continue;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                    int nodeNo = row * n + col;
                    int adjNodeNo = newr * n + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // step 2
    int mx = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 1) continue;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for (int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n)) {
                    if (grid[newr][newc] == 1) {
                        components.insert(ds.findUltimateParent(newr * n + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : components) {
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; cellNo++) {
        mx = max(mx, ds.size[ds.findUltimateParent(cellNo)]);
    }
    return mx;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}