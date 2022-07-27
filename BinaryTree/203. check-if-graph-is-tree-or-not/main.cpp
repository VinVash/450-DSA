#include <bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	list<int> *adj; // every vertex's adjacency list, i.e., adjacency list of v vertices.
	bool isCycleUtil(int v, vector<bool> &visited, int parent);
public:
	Graph(int v); // Constructor
	void addEdge(int v, int w); // to add an edge to the graph
	bool isTree(); // returns true if the graph is a tree.
};

Graph::Graph(int v) {
	this-> v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::isCycleUtil(int v, vector<bool> &visited, int parent) {
	visited[v] = true; // this node is reachable from the root.

	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++) {
		if(!visited[*i]) { // i is not visited.
			if (isCycleUtil(*i, visited, v))
				return true;
		}
		else if(*i != parent) // i is already visited.
			return true;
	}

	return false; // if nothing has been returned till now.
}

bool Graph::isTree() {
	vector<bool> visited(v, false);

	if(isCycleUtil(0, visited, -1))
		return false;

	for(int u = 0; u < v; u++) {
		if(!visited[u])
			return false;
	}

	return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

	return 0;
}