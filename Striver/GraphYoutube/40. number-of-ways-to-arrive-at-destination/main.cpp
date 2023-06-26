#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: ElogV (simply Dijkstra's algo)
// Space complexity: O(N)

int countPaths(int n, vector<vector<int>>& roads) {

	// create adjList
	vector<pair<int, int>> adj[n];
	for(auto it: roads) {
		adj[it[0]].push_back({ it[1], it[2] });
		adj[it[1]].push_back({ it[0], it[2] });
	}

	// create priority queue
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// create the dist and ways arrays.
	vector<int> dist(n, 1e9);
	vector<int> ways(n, 0);
	dist[0] = 0;
	ways[0] = 1;
	pq.push({ 0, 0 }); // distance of 0 of node 0.

	int mod = (int)(1e9 + 7);
	while(!pq.empty()) {
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for(auto it: adj[node]) {
			int adjNode = it.first;
			int edgeWeight = it.second;

			if(dis + edgeWeight < dist[adjNode]) { // first time some path has reached with such a short distance.
				dist[adjNode] = dis + edgeWeight;
				pq.push({ dis + edgeWeight, adjNode });
				ways[adjNode] = ways[node];
			} else if(dis + edgeWeight == dist[adjNode]) { // another time some path reached with the same shortest distance.
				ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
			}
		}
	}

	return ways[n-1] % mod;


}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}