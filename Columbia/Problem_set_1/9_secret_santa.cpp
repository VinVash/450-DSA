#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> arr(n+1);
	for(int i = 1; i <= n; i++) cin >> arr[i];

	vector<int> b(n+1, 0);
    vector<bool> gift_taken(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!gift_taken[arr[i]]) {
            b[i] = arr[i];
            gift_taken[arr[i]] = true;
        }
    }

    vector<int> empty_indices;
    vector<int> unused_values;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) empty_indices.push_back(i);
        if (!gift_taken[i]) unused_values.push_back(i);
    }

    for (int i = 0; i < empty_indices.size(); i++) {
        b[empty_indices[i]] = unused_values[i];
    }

    if (empty_indices.size() == 1) {
        int idx = empty_indices[0];

        if (b[idx] == idx) {    
            int desired = arr[idx];
            
            // search who has 'desired'
            for(int i=1; i<=n; i++) {
                if (i != idx && b[i] == desired) {
                    b[i] = idx;
                    b[idx] = desired;
                    break;
                }
            }
        }
    } else if (empty_indices.size() > 1) {
        
        for (int i = 0; i < empty_indices.size(); i++) {
            int u = empty_indices[i];
            if (b[u] == u) {
                int v = empty_indices[(i+1) % empty_indices.size()];
                swap(b[u], b[v]);
            }
        }
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == arr[i]) k++;
    }

    cout << k << endl;
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;

    while(t--) {
    	solve();
    }


	return 0;
}