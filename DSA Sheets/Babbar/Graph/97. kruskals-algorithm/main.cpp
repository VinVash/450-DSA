#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
	for(int i=0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(vector<int> &parent, int node) {
	if(parent[node] == node)
		return node;

	parent[node] = findParent(parent, parent[node]);
	return parent[node];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
	u = findParent(parent, u);
	v = findParent(parent, v);

	if(rank[u] < rank[v]) {
		parent[u] = v;
	} else if(rank[v] == rank[u]) {
		parent[v] = u;
	} else {
		parent[v] = u;
		rank[u]++;
	}
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {

	// sort edges.
	sort(edges.begin(), edges.end(), cmp);

	vector<int> parent(n);
	vector<int> rank(n);
	makeSet(parent, rank, n);

	int minWeight = 0;

	for(int i = 0; i < edges.size(); i++) {
		// find out parents of the nodes to find out whether they lie in the same component or not.
		int u = findParent(parent, edges[i][0]);
		int v = findParent(parent, edges[i][1]);
		int w = edges[i][2];

		if(u != v) {
			minWeight += w;
			unionSet(u, v, parent, rank);
		}
	}

	return minWeight;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}

// Acc. to studies, the findParent and unionSet functions run in O(1) time, i.e., constant.
// Therefore the time complexity:
// 		sorting: O(mlogm), where m is the number of edges
// 		for-loop: O(m) * O(1) = O(m)
// 		Final: O(mlogm)