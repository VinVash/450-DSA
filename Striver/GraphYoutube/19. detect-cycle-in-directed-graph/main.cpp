#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;


/* Approach 1: With two arrays: vis and pathVis. */

bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]) {
	vis[node] = 1;
	pathVis[node] = 1;

	for(auto it: adj[node]) {
		if(!vis[it]) {
			if(dfs(it, vis, pathVis, adj))
				return true;
		} else if(pathVis[it]) {
			return true;
		}
	}

	pathVis[node] = 0;
	return false;
}

bool isCyclic(int V, vector<int> adj[]) {
	vector<int> vis(V, 0);
	vector<int> pathVis(V, 0);

	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			if(dfs(i, vis, pathVis, adj))
				return true;
		}
	}

	return false;
}


/* Approach 2: With only one vis array: mark 1 for marking visited, and 2 for marking pathVisited */

bool dfs(int node, vector<int>& vis, vector<int> adj[]) {
	vis[node] = 2;
	// pathVis[node] = 1;

	for(auto it: adj[node]) {
		if(!vis[it]) {
			if(dfs(it, vis, adj))
				return true;
		} else if(vis[it] == 2) {
			return true; 
		}
	}

	vis[node] = 1;
	return false;
}

bool isCyclic(int V, vector<int> adj[]) {
	vector<int> vis(V, 0);
	vector<int> pathVis(V, 0);

	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			if(dfs(i, vis, adj))
				return true;
		}
	}

	return false;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}