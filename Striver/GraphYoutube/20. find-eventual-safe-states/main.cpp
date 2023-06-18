#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(N X M)
// Space complexity: O(N X M)

bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[], vector<int>& check) {
	vis[node] = 1;
	pathVis[node] = 1;
	check[node] = 0;

	for(auto it: adj[node]) {
		if(!vis[it]) {
			if(dfs(it, vis, pathVis, adj, check)) {
				check[node] = 0;
				return true;
			}
		} else if(pathVis[it]) {
			check[node] = 0;
			return true; 
		}
	}

	check[node] = 1;
	pathVis[node] = 0;
	return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
	vector<int> vis(V, 0);
	vector<int> pathVis(V, 0);

	vector<int> check(V, 0);
	vector<int> safeNodes;

	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			dfs(i, vis, pathVis, adj, check);
		}
	}

	for(int i = 0; i < V; i++) {
		if(check[i] == 1)
			safeNodes.push_back(i);
	}

	return safeNodes;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}