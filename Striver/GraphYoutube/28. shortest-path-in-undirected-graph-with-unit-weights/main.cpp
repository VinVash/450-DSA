#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// The queue here is already sorted as we push new elements into it.

// Time complexity: O(V + 2E)
// Space complexity: O(N)

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
	vector<int> adj[N];
	for(auto it: edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	int dist[N];
	for(int i = 0; i < N; i++)
		dist[i] = 1e9; // mark every node as infinity.

	dist[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(auto it: adj[node]) {
			if(dist[node] + 1 < dist[it]) {
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}

	vector<int> ans(N, -1);
	for(int i = 0; i < N; i++) {
		if(dist[i] != 1e9)
			ans[i] = dist[i];
		else
			ans[i] = -1;
	}

	return ans;

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}