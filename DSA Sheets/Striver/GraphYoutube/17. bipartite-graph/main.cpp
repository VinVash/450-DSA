#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

/* BFS Approach*/

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


/* DFS Approach*/

bool dfs(int node, int cl, vector<int>& color, vector<int> adj[]) {
	color[node] = cl;

	for(auto adjNode: adj[node]) {
		if(color[adjNode] == -1) {
			if(dfs(adjNode, !cl, color, adj) == false)
				return false;
		} else if(color[adjNode] == cl) {
			return false;
		}
	}

	return true;
}

bool isBipartite(int V, vector<int> adj[]) {
	vector<int> color(V, -1);

	for(int i = 0; i < V; i++) {
		if(color[i] == -1) {
			if(dfs(i, 0, color, adj) == false)
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