#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

class DisjointSet {
public:
	vector<int> rank, parent, size;

	DisjointSet(int n) {
		rank.resize(n+1, 0);
		parent.resize(n+1, 0);
		size.resize(n+1, 0);
		for(int i = 0; i <= n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findUltimateParent(int node) {
		if(node == parent[node])
			return node;
		return parent[node] = findUltimateParent(parent[node]);
	}

	void unionByRank(int u, int v) {
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);

		if(ulp_u == ulp_v)
			return;
		if(rank[ulp_u] < rank[ulp_v])
			parent[ulp_u] = ulp_v;
		else if(rank[ulp_v] < rank[ulp_u])
			parent[ulp_v] = ulp_u;
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}

	void unionBySize(int u, int v) {
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);

		if(ulp_u == ulp_v)
			return;

		if(size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		} else {
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}

	}
};

vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
	int n = details.size();

	DisjointSet ds(n);

	unordered_map<string, int> mapMailNode;

	for(int i = 0; i < n; i++) {
		for(int j = 1; j < details[i].size(); j++) {
			string mail = details[i][j];

			// if mapMailNode doesn't contains mail node.
			if(mapMailNode.find(mail) == mapMailNode.end()) {
				mapMailNode[mail] = i;
			} else { // if mapMailNode contains it.
				ds.unionBySize(i, mapMailNode[mail]);
			}
		}
	}

	vector<string> mergeMail[n];
	for(auto it: mapMailNode) {
		string mail = it.first;
		int node = ds.findUltimateParent(it.second);

		mergeMail[node].push_back(mail);
	}

	vector<vector<string>> ans;

	for(int i = 0; i < n; i++) {
		if(mergeMail[i].size() == 0) continue;

		sort(mergeMail[i].begin(), mergeMail[i].end());

		vector<string> temp;
		temp.push_back(details[i][0]);
		for(auto it: mergeMail[i]) {
			temp.push_back(it);
		}

		ans.push_back(temp);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}