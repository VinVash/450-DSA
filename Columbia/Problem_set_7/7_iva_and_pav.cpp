#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> p(n+1, vector<int>(30, 0));
    for(int i = 1; i<= n; i++) {
        cin >> a[i];

        for(int j = 0; j < 30; j++) {
            p[i][j] = p[i-1][j];
            if((a[i] >> j) & 1) {
                p[i][j]++;
            }
        }
    }


    int q; cin >> q;
    while(q--) {
        int l, k; cin >> l >> k;


        if(a[l] < k) {
            cout << -1 << " ";
            continue;
        }

        int low = l;
        int high = n; 
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low) / 2;
            int val = 0;

            for(int j = 0; j < 30; j++) {
                if(p[mid][j] - p[l-1][j] == mid-l+1) {
                    val += (1 << j);
                }
            }

            if(val >= k) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        cout << ans << " ";

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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}