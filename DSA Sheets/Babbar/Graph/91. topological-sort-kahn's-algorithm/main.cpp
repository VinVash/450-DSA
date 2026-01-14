#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
	unordered_map<int, list<int>> adj;

	// create adjList
	for(int i = 0; i < e; i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// find all indegrees
	vector<int> indegree(v);
	for(auto i: adj) {
		for(auto j: i.second)
			indegree[j]++;
	}

	// push elements with 0 indegree in queue.
	queue<int> q;

	for(int i = 0; i < v; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	// do bfs
	vector<int> ans;
	while(q.size()) {
		int front = q.front();
		q.pop();

		// store ans
		ans.push_back(front);

		// update indegree of neigbours
		for(auto neighbour: adj[front]) {
			indegree[neighbour]--;
			if(indegree[neighbour] == 0)
				q.push(neighbour);
		}
	}
	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}