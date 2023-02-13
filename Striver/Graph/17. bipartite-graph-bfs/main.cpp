#include <bits/stdc++.h>
using namespace std;

// colors an individual component.
bool check(int start, vector<int> adj[], vector<int> &color) {
	queue<int> q;
	q.push(start);
	color[start] = 0;

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto it: adj[node]) {
			if(color[it] == -1) {
				color[it] = !color[node];
				q.push(it);
			} else if (color[it] == color[node]) {
				return false;
			}
		}
	}

	return true;
}

// Time and space complexities are the same as BFS algorithm.
bool isBipartite(int V, vector<int> adj[]) {
	vector<int> color(V, -1);

	for(int i = 0; i < V; i++) {
		if(color[i] == -1) {
			if(check(i, adj, color) == false)
				return false;
		}
	}

	return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}