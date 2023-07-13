#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Shortest path in weighted undirected graph.

// Time complexity: O(ElogV) + O(n) [extra for backtracking]
// Space complexity: O(n). using different arrays such as dist, parent, path.

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
	vector<pair<int, int>> adj[n+1];
	for(auto it: edges) {
		adj[it[0]].push_back({ it[1], it[2] });
		adj[it[1]].push_back({ it[0], it[2] });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
	vector<int> dist(n+1, 1e9);
	vector<int> parent(n+1);
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	dist[1] = 0;
	pq.push({ 0, 1 });

	while(!pq.empty()) {
		int node = pq.top().second;
		int dis = pq.top().first;
		pq.pop();

		for(auto it: adj[node]) {
			int adjNode = it.first;
			int edgeWeight = it.second;
			if(dis + edgeWeight < dist[adjNode]) {
				dist[adjNode] = dis + edgeWeight;
				pq.push({ dis + edgeWeight, adjNode });
				parent[adjNode] = node;
			}
		}
	}

	if(dist[n] == 1e9)
		return {-1};
	vector<int> path;
	int node = n;
	while(parent[node] != node) {
		path.push_back(node);
		node = parent[node];
	}

	path.push_back(1);
	reverse(path.begin(), path.end());
	return path;

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}