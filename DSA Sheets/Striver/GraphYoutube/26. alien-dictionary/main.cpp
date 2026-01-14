#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// When the order will not be possible:
// 1.) s1 = abcd and s2 = abc, the shorter string will always come before the largeer string.
// 2.) if there is a cyclic dependency, not possible. Dictionary is wrong.

// Time complexity: 
// Space complexity: 

vector<int> topoSort(vector<int> adj[], int V) {
	int indegree[V] = {0};
	for(int i = 0; i < V; i++) {
		for(auto it: adj[i])
			indegree[it]++;
	}

	queue<int> q;
	for(int i = 0; i < V; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}

	vector<int> topo;
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

	return topo;
}

string findOrder(string dict[], int N, int K) {
	vector<int> adj[K];
	for(int i = 0; i < N-1; i++) {
		string s1 = dict[i], s2 = dict[i+1];
		int len = min(s1.size(), s2.size()); 
		for(int ptr = 0; ptr < len; ptr++) {
			if(s1[ptr] != s2[ptr]) {
				adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); 
				break; 
			}
		}
	}

	vector<int> topo = topoSort(adj, K);
	string ans = "";
	for(auto it: topo) {
		ans = ans + char(it + 'a');
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