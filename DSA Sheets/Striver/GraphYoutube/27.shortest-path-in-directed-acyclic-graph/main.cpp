#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

void dfs(int node, vector<pair<int, int>> adj[], int vis[], stack<int>& stk) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        int v = it.first;
        if(!vis[v]) {
            dfs(v, adj, vis, stk);
        }
    }
    
    
    stk.push(node);
}

 vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[M];
    for(int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({ v, wt });
    }
    
    // find the topo sort
    // O(N+M)
    int vis[N] = {0};
    stack<int> stk;
    for(int i = 0; i < N ;i++) {
        if(!vis[i])
            dfs(i, adj, vis, stk);
    }
    
    // step 2: do the distance thing.
    vector<int> dist(N, 1e9); // set all vertices' distance to infinity.
    dist[0] = 0; // dist of src node is 0.
    
    // O(N+M)
    while(!stk.empty()) {
        int node = stk.top();
        stk.pop();
        
        for(auto it: adj[node]) {
            int v = it.first;
            int wt = it.second;
            
            if(dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }

    for(int i = 0; i < dist.size(); i++) {
        if(dist[i] == 1e9)
            dist[i] = -1;
    }
    
    return dist;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}