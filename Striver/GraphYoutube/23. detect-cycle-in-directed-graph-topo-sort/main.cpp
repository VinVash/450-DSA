#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

bool isCyclic(int V, vector<int> adj[]) {
	vector<int> indegree(V, 0);
	
	for(int i = 0; i < V; i++) {
	    for(auto it: adj[i]) {
	        indegree[it]++;
	    }
	}
	
	vector<int> topo; // to store the topological sort.
	
	queue<int> q;
	for(int i = 0; i < V; i++) {
	    if(indegree[i] == 0)
	        q.push(i);
	}
	
	while(!q.empty()) {
	    int node = q.front();
	    q.pop();
	    
	    topo.push_back(node);
	    
	    for(auto it: adj[node]) {
	        indegree[it]--;
	        if(indegree[it] == 0)
	            q.push(it);
	    }
	}
	
	return topo.size() != V;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}