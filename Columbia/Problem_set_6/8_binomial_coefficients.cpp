#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAX = 100005;

int pow2[MAX];

void precompute() {
    pow2[0] = 1;
    for (int i = 1; i < MAX; i++) {
        pow2[i] = (1LL * pow2[i-1] * 2) % MOD;
    }
}

void solve() {
    int t; cin >> t;

    vector<int> nval(t);
    for (int i = 0; i <t; i++) cin >> nval[i];

    for (int i = 0; i< t; i++) {
        int k; cin >> k;
        if (k < MAX) {
            cout << pow2[k] << (i == t-1 ? "" : "\n");
        }
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

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    precompute();
    solve();

	return 0;

}