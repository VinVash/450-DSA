#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: 4 * ⍺ (⍺ is a constant) ~ constant.

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

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    // if 3 and 7 are in the same component or not.
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
    	cout << "Same" << endl;
    else
    	cout << "Not same" << endl;

    ds.unionBySize(3, 7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7))
    	cout << "Same" << endl;
    else
    	cout << "Not same" << endl;

 	return 0;
}