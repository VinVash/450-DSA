#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// For both the approaches
// Time Complexity: O(V + 2E) + O(N) -> if multiple components
// Space complexity: O(N)

bool detect(int src, vector<int> adj[], int vis[]) {
	vis[src] = 1;
	queue<pair<int, int>> q;
	q.push({ src, -1 });

	while(q.size()) {
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for(auto adjacentNode: adj[node]) {
			if(!vis[adjacentNode]) {
				vis[adjacentNode] = 1;
				q.push({ adjacentNode, node });
			} else if(parent != adjacentNode) {
				return true;
			}
		}
	}

	return false;
}

bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
	vis[node] = 1;
	for(auto neighbour: adj[node]) {
		if(!vis[neighbour]) {
			if(dfs(neighbour, node, vis, adj) == true)
				return true;
		} else if(neighbour != parent)
			return true;
	}

	return false;
}

bool isCycle(int V, vector<int> adj[]) {
	int vis[V] = {0};
	
	for(int i = 0; i < V; i++) { // for loop to ensure for disconnected components.
		if(!vis[i]) {
			if(detect(i, adj, vis))
				return true;
		}
	}

	/* Or this appraoch */
	// for(int i = 0; i < V; i++) { // for loop to ensure for disconnected components.
	// 	if(!vis[i]) {
	// 		if(dfs(i, -1, vis, adj) == true)
	// 			return true;
	// 	}
	// }


	return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}