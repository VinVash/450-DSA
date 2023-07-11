#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(V + E) // in case of directed graph.


vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
	vector<int> indegree(V, 0);
    vector<int> adjRev[V];
	for(int i = 0; i < V; i++) {
		for(auto it: adj[i]) {
			adjRev[it].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for(int i = 0; i < V; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	vector<int> safeNodes;

	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		safeNodes.push_back(node);
		
		for(auto it: adjRev[node]) {
			indegree[it]--;
			if(indegree[it] == 0)
				q.push(it);
		}
	}

	sort(safeNodes.begin(), safeNodes.end());

	return safeNodes;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}