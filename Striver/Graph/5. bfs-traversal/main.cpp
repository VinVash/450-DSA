#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N + 2E)
vector<int> bfsOfGraph(int v, vector<int> adj[]) {
	vector<int> vis(v, 0);
	vis[0] = 1;
	queue<int> q;
	q.push(0);

	vector<int> bfs;
	while(!q.empty()) {
		// since we are removing it from the queue, it is already marked visited.
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for(auto it: adj[node]) {
			if(!vis[it]) {
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	return bfs;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}