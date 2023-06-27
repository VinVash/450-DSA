#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(V * E)
// Space complexity: O(V)

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
	vector<int> dist(V, 1e8);
	dist[S] = 0;
	for(int i = 0; i < V-1; i++) {
		for(auto it: edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	// Nth relaxation to check negative cycle
	for(auto it: edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			return {-1};
		}
	}

	return dist;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}