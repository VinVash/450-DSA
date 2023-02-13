#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N + E).
bool checkCycleDFS(int i, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj) {
	visited[node] = true;
	dfsVisited[node] = true;

	for(auto neighbour: adj[node]) {
		if(!visited[neighbour]) {
			bool cycle = checkCycleDFS(neighbour, visited, dfsVisited, adj);
			if(cycle) {
				return true;
			} else {
				// visited = true.
				if(dfsVisited[node] == true) {
					return true;
				}
			}
		}
	}

	dfsVisited[node] = false;
	return false;
}

int detectCycleDirected(int n, vector<pair<int, int>> &edges) {
	// create adjList
	unordered_map<int, list<int, int>> adj;
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
	}

	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisited;

	for(int i = 0; i <= n; i++) { // for loop to ensure for disconnected components.
		if(!visited[i]) {
			bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
			if(cycleFound)
				return true;
		}
	}

	return false;
}

/*
	Alternative solution:

	bool checkCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto adjNode: adj[node]) {
            if(!vis[adjNode]) {
                bool cycle = checkCycle(adjNode, adj, vis, dfsVis);
                if(cycle)
                    return true;
            } else if(dfsVis[adjNode]) {
                return true;
            }
        }
        
        dfsVis[node] = 0;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> dfsVis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                bool cycle = checkCycle(i, adj, vis, dfsVis);
                if(cycle)
                    return true;
            }
        }
        
        return false;
    }
*/

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}