#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
	vector<int> res;

    priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>      > pq;

    for(int i = 0; i < k; i++) {
      pq.push({ kArrays[i][0], { i, 0} });
    }

    vector<int>ans;

    while(!pq.empty()) {

    	int val = pq.top().first;

    	int arr = pq.top().second.first;
    	int idx = pq.top().second.second;
    	pq.pop();

        ans.push_back(val);
        
        if(kArrays[arr].size() > idx+1) {
            pq.push({ kArrays[arr][idx+1], { arr, idx+1 } });
        }
    }

    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	int k; cin >> k;

	vector<vector<int>> kArrays;

	for(int i = 0; i < k; i++) {
		int n; cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
		    cin >> nums[i];

		kArrays.push_back(nums);
	}

	vector<int> ans = mergeKSortedArrays(kArrays, k);

	for(auto i: ans)
		cout << i << " ";
	cout << endl;

	return 0;
}