#include <bits/stdc++.h>
using namespace std;

int detectCycleDirected(int n, vector<pair<int, int>> &edges) {
	unordered_map<int, list<int>> adj;

	// create adjList
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i].first - 1; // because the index is starting from 1.
		int v = edges[i].second - 1; // because the index is starting from 1.

		adj[u].push_back(v);
	}

	// find all indegrees
	vector<int> indegree(n);
	for(auto i: adj) {
		for(auto j: i.second)
			indegree[j]++;
	}

	// push elements with 0 indegree in queue.
	queue<int> q;

	for(int i = 0; i < n; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	// do bfs
	int count = 0;
	while(q.size()) {
		int front = q.front();
		q.pop();

		// increment count
		count++;

		// update indegree of neigbours
		for(auto neighbour: adj[front]) {
			indegree[neighbour]--;
			if(indegree[neighbour] == 0)
				q.push(neighbour);
		}
	}
	
	if(count == n) // valid topological sort. therefore not cyclic.
		return false;
	else
		return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}