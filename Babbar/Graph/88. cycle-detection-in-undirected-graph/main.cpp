#include <bits/stdc++.h>
using namespace std;

// BFS method: maintain a queue.
// while queue is not empty, pop from queue, check for neigbours of that popped element.
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adj[front]) {
            if(visited[neighbour] == true && neighbour != parent[front])
                return true;
            else if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    
    return false;
}

bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
	visited[node] = true;

	for(auto neighbour: adj[node]) {
		if(!visited[neighbour]) {
			bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
			if(cycleDetected)
				return true;
		} else if(neighbour != parent) {
			return true;
		}
	}
	return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // to handle disconnected components
    unordered_map<int, bool> visited;
    
    for(int i=0; i < V; i++) {
        if(!visited[i]) {
            // bool ans = isCyclicBFS(i, visited, adj);
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1)
                return 1;
        }
    }
    
    return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}