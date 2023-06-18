#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

vector<int> topoSort(int V, vector<int> adj[]) {

	// find all indegrees
	vector<int> indegree(V, 0);
	for(int i = 0; i < V; i++) {
		for(auto it: adj[i])
			indegree[it]++;
	}

	// push elements with 0 indegree in queue.
	queue<int> q;
	for(int i = 0; i < V; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	// do bfs
	vector<int> topo;
	while(!q.empty()) {
		int node = q.front();
		q.pop();

		// store ans
		topo.push_back(node);

		// update indegree of neigbours - node is in toposort vector, so please remove it from your indegree.
		for(auto it: adj[node]) {
			indegree[it]--;

			if(indegree[it] == 0)
				q.push(it);
		}
	}

	return topo;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}