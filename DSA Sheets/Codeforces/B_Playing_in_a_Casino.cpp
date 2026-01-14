#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define int long long


signed main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> v(m, vector<int>(n));
		
		for(int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
				int t;
				cin >> t;
				v[j][i] = t;
			}
		}

		if (n == 1) {
			cout << 0 << endl;
			continue;
		}

		int sum = 0;
		for (int i = 0; i < m; i++) {
			sort(v[i].begin(), v[i].end());
			for (int j = 0; j < n; j++) {
				int k = n - (j+1);
				
				sum += ((j) * v[i][j]) - k*v[i][j];
			}
			
		}
		cout << sum << endl;
	}


	return 0;
}