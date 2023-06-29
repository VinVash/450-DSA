#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& stk) {
	vis[node] = 1;

	for(auto it: adj[node]) {
		if(!vis[it])
			dfs(it, vis, adj, stk);
	}


	// when the dfs traversal is over.
	stk.push(node);
}

void dfs3(int node, vector<int>& vis, vector<int> adjT[]) {
	vis[node] = 1;
	for(auto it: adjT[node]) {
		if(!vis[it]) {
			dfs3(it, vis, adjT);
		}
	}
}

int kosaraju(int V, vector<int> adj[]) {

	// O(V) + O(V) = O(2V) space.
	vector<int> vis(V, 0);
	stack<int> stk;

	// O(V + E)
	for(int i = 0; i < V; i++) {
		if(!vis[i])
			dfs(i, vis, adj, stk);
	}

	// O(V + E) space in storing the full graph.
	vector<int> adjT[V]; // store the reversed (transposed) graph.

	// O(V + E)
	for(int i = 0; i < V; i++) {
		vis[i] = 0; // mark every node as unvisited, so we can use the same vis array below.
		for(auto it: adj[i]) {
			// i -> it.
			// it -> i. (after reversing)
			adjT[it].push_back(i);
		}
	}

	int scc = 0;
	// O(V + E)
	while(!stk.empty()) {
		int node = stk.top();
		stk.pop();

		if(!vis[node]) {
			scc++;
			dfs3(node, vis, adjT); // dfs3 because it is the 3rd step.
		}
	}

	return scc;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}