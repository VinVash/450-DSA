#include <bits/stdc++.h>
using namespace std;

/*
	Topological sort is only applicable on DAGs. (Directed Acyclic Graphs)
*/

int detectCycleDirected(int n, vector<pair<int, int>> &edges) {
	unordered_map<int, list<int>> adj;

	// create adjList
	for(int i = 0; i < edges.size(); i++) {
		int u = edges[i].first - 1; // because the index is starting from 1.
		int v = edges[i].second - 1; // because the index is starting from 1.

		adj[u].push_back(v);
	}

	// find all indegrees
	vector<int> indegree(n);
	for(auto i: adj) {
		for(auto j: i.second)
			indegree[j]++;
	}

	// push elements with 0 indegree in queue.
	queue<int> q;

	for(int i = 0; i < n; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	// do bfs
	int count = 0;
	while(q.size()) {
		int front = q.front();
		q.pop();

		// increment count
		count++;

		// update indegree of neigbours
		for(auto neighbour: adj[front]) {
			indegree[neighbour]--;
			if(indegree[neighbour] == 0)
				q.push(neighbour);
		}
	}
	
	// If toposort has exactly n elements, than it is a DAG. If less, than it has a cycle.
	if(count == n) // valid topological sort. therefore not cyclic.
		return false;
	else
		return true;
}

/*
	Alternative solution

	bool isCyclic(int n, vector<int> adj[]) {
        vector<int> indegree(n);
        for(int i = 0; i < n; i++) {
            for(auto j: adj[i])
                indegree[j]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            count++;
            for(auto adjNode: adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        
        if(count == n)
            return false;
        else
            return true;
    }

*/

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}