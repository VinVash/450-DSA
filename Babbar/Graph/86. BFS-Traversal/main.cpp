#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges) {
	for(int i=0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].insert(v);
		adjList[v].insert(u);
	}
}

// O(N+E).
void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &res, int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while(!q.empty()) {
		int frontNode = q.front();
		q.pop();

		// store frontNode into ans
		res.push_back(frontNode);

		// traverse all neighbours of frontNode.
		for(auto i: adjList[frontNode]) {
			if(!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    // we are given vertex => no. of vertices, and
    // edges => vector of edges.

	unordered_map<int, set<int>> adjList;
	vector<int> res; // stores the BFS traversal.
	unordered_map<int, bool> visited;

	prepareAdjList(adjList, edges);

	// traverse all components of a graph
	for(int i=0; i < vertex; i++) {
		if(!visited[i]) {
			bfs(adjList, visited, res, i);
		}
	}

	return res;

	return 0;
}