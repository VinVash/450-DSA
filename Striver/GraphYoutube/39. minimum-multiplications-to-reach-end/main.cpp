#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(100000 * 100000) -> very hypothetical situation, worst case, very rare

int minimumMultiplications(vector<int>& arr, int start, int end) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	vector<int> dist(100000, 1e9); // hence, the nodes will be numbered 0 to 99999.
	dist[start] = 0;

	int mod = 100000;
	while(!q.empty()) {
		int node = q.front().first;
		int steps = q.front().second;
		q.pop();

		for(auto it: arr) {
			int num = (it * node) % mod;
			if(steps + 1 < dist[num]) {
				dist[num] = steps + 1;
				if(num == end) return steps + 1;
				q.push({ num, steps + 1 });
			}
		}
	}

	return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
    vi arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

   	int start, end;
   	cin >> start >> end;

   	cout << "start: " << start << endl;
   	cout << "end: " << end << endl;

   	cout << minimumMultiplications(arr, start, end) << endl;

	return 0;
}