#include <bits/stdc++.h>
using namespace std;

// Djikstra Algorithm, Time: O(E*logV), Space: O(N+E)
vector<int> djikstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

	// create adjList
	unordered_map<int, list<pair<int, int>>> adj;
	for(int i = 0; i < vertices; i++) {
		int u = vec[i][0];
		int v = vec[i][1];
		int w = vec[i][2];

		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	// make dist. array initialised with infinite value
	vector<int> dist(vertices, INT_MAX);

	// creation of set on basis (distance, node)
	set<pair<int, int>> st;

	// initialise distance and set with source node
	dist[source] = 0;
	st.insert(make_pair(0, source));

	while(st.size()) {
		
		// fetch top record
		auto top = *(st.begin());

		int nodeDistance = top.first;
		int topNode = top.second;

		// remove top record
		st.erase(st.begin());

		// traverse on neighbours
		for(auto neighbour: adj[topNode]) {
			if(nodeDistance + neighbour.second < dist[neighbour.first]) {
				auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

				// if record found, then erase it
				if(record != st.end()) {
					st.erase(record);
				}

				// distance update
				dist[neighbour.first] = nodeDistance + neighbour.second;

				// push in set
				st.insert(make_pair(dist[neighbour.first], neighbour.first));
			}
		}
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