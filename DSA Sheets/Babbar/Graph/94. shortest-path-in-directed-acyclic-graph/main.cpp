#include <bits/stdc++.h>
using namespace std;

class Graph {
	public:
		unordered_map<int, list<pair<int, int>>> adj;

		void addEdge(int u, int v, int weight) {
			pair<int, int> p = make_pair(v, weight);
			adj[u].push_back(p);
		}

		void printAdj() {
			for(auto i: adj) {
				cout << i.first << " -> ";
				for(auto j: i.second) {
					cout << "(" << j.first << ", " << j.second << "), ";
				}
				cout << endl;
			}
		}

		// this function is basically topological sort.
		void dfs(int node, unordered_map<int, bool> &visited, stack<int> &stk) {
			visited[node] = true;

			for(auto neighbour: adj[node]) {
				if(!visited[neighbour.first]) {
					dfs(neighbour.first, visited, stk);
				}
			}

			stk.push(node); // topological sort step. Everyone knows this famous step.
		}

		void getShortestPath(int src, vector<int> &dist, stack<int> &stk) {
			dist[src] = 0;

			while(stk.size()) { // while the stack is not empty.
				int top = stk.top();
				stk.pop();

				if(dist[top] != INT_MAX) {
					for(auto i: adj[top]) {
						if(dist[top] + i.second < dist[i.first]) {
							dist[i.first] = dist[top] + i.second;
						}
					}
				}
			}
		}
};

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Graph g;
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 6);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5 ,-2);

	g.printAdj();
	int n = 6;
	unordered_map<int, bool> visited;
	stack<int> stk;

	// topological sort
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			g.dfs(i, visited, stk); // no need to pass adj since it is available in the class.
		}
	}

	int src = 1; // starting node
	vector<int> dist(n, INT_MAX);

	// Time: O(N+E)
	// Space: O(N+E)
	g.getShortestPath(src, dist, stk);

	cout << "Ans is: " << endl;

	for(int i=0; i < dist.size(); i++) {
		cout << dist[i] << " ";
	}
	cout << endl;

	return 0;
}