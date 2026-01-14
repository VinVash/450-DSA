#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

void dfs(int node, vi& vis, stack<int>& stk, vi adj[]) {
	vis[node] = 1;
	for(auto it: adj[node]) {
		if(!vis[it])
			dfs(i, vis, stk, adj);
	}

	stk.push(node);
}

vi topoSort(int V, vi adj[]) {
	vi vis(V, 0);
	stack<int> stk;
	for(int i = 0; i < V; i++) {
		if(!vis[i]) {
			dfs(i, vis, stk, adj);
		}
	}

	vi ans;
	while(!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
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