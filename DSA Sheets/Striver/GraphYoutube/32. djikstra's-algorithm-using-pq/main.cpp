#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(V^2), but with min priority queue: O(V + ElogV) = O(ElogV)
// Space complexity: 

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
	vector<int> dist(V, 1e9); // mark all nodes as infinity.

	dist[S] = 0;
	pq.push({ 0, S });

	while(!pq.empty()) {
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for(auto it: adj[node]) {
			int edgeWeight = it[1];
			int adjNode = it[0];

			if(dis + edgeWeight < dist[adjNode]) {
				dist[adjNode] = dis + edgeWeight;
				pq.push({ dist[adjNode], adjNode });
			}
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