#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component) {
	component.push_back(node);
	visited[node] = true;

	// hr connected node ke liye recursive call
	for(auto i: adjList[node]) {
		if(!visited[i]) {
			dfs(i, visited, adjList, component);
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// we have V, E, adjList given.

	vector<vector<int>> res;
	unordered_map<int, bool> visited;

	// for all nodes call DFS if not visited, (covering non-connected components).
	for(int i = 0; i < V; i++) {
		if(!visited[i]) {
			vector<int> component;
			dfs(i, visited, adjList, component);
			res.push_back(component);
		}
	}

	return res;

	return 0;
}