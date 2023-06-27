#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Greedy intuition in this algorithm.
// Time complexity: ElogE + ElogE (ElogE -> iteration, ElogE -> traversing the adj. and putting them in the pq.)
// Space complexity: O(V) + O(E) (V -> visited, E -> priority queue max size.)

int spanningTree(int V, vector<vector<int>> adj[]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> vis(V, 0);
	int sum = 0;

	// only store the weight and the node, no need to store the parent. (parent is needed for MST)
	// but here we need only the sum of the weights.

	pq.push({ 0, 0 });

	// O(E)
	while(!pq.empty()) {

		// log E
		auto it = pq.top();
		pq.pop();

		int node = it.second;
		int weight = it.first;

		if(vis[node] == 1) continue; // already part of the MST.

		// else go ahead, and be a part of the MST.
		vis[node] = 1;
		sum += weight;

		// Overall, across all the iterations, we will move across all the edges.
		// E log E
		for(auto it: adj[node]) {
			int adjNode = it[0];
			int edgeWeight = it[1];

			if(!vis[adjNode]) {
				pq.push({ edgeWeight, adjNode });
			}
		}
	}

	return sum;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}