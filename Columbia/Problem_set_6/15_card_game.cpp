#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;
ll C[65][65];
ll ansA[35], ansB[35];

void solve() {
    int n;
    cin >> n;
    int k = n/2;
    cout << ansA[k] << " " << ansB[k] << " 1" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    for (int i = 0; i <=60; i++) {
        C[i][0] = 1;
        for (int j = 1; j <=i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }

    ansA[1] = 1;
    ansB[1] = 0;
    for (int k = 2; k <= 30; k++) {
        ansA[k] = (C[2*k - 1][k-1] + ansB[k-1]) % MOD;
        ansB[k] = (C[2*k][k] -ansA[k]-1) % MOD;
        ansB[k] = (ansB[k] + MOD) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}