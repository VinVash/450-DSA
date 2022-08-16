#include <bits/stdc++.h>
using namespace std;

// Time: O(N+E), Space: O(N+E).
vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int m, int s, int t) {
	
	// create adjList
	unordered_map<int, list<int>> adj;
	for(int i=0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// do bfs
	unordered_map<int, bool> visited;
	unordered_map<int, bool> parent;
	queue<int> q;
	q.push(s); // s = src node.
	parent[s] = -1; // parent of src node.
	visited[s] = true;
	
	while(q.size()) {
		int front = q.front();
		q.pop();

		for(auto neighbour: adj[front]) {
			if(!visited[neighbour]) {
				visited[neighbour] = true;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}

	// prepare shortest path
	vector<int> res;
	int currentNode = t;
	res.push_back(t);

	while(currentNode != s) {
		currentNode = parent[currentNode];
		res.push_back(currentNode);
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}