#include <bits/stdc++.h>
using namespace std;

// O(nlogn)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k) {
	vector<int> res;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	priority_queue<pair<int, pair<int, int>>> pq;
	set<pair<int,int>> indices;

	pq.push(make_pair(a[n-1] + b[n-1], make_pair(n-1, n-1)));
	indices.insert(make_pair(n-1, n-1));

	for(int count = 0; count < k; count++) {
		pair<int, pair<int, int>> temp = pq.top();
		pq.pop();

		res.push_back(temp.first); // pushing back the score

		int i = temp.second.first, j = temp.second.second;

		int sum = a[i-1] + b[j];
		pair<int, int> temp1 = make_pair(i-1, j);

		// if temp1 is not present in indices.
		if(indices.find(temp1) == indices.end()) {
			pq.push(make_pair(sum, temp1));
			indices.insert(temp1);
		}

		sum = a[i] + b[j-1];
		temp1 = make_pair(i, j-1);

		if(indices.find(temp1) == indices.end()) {
			pq.push(make_pair(sum, temp1));
			indices.insert(temp1);
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}