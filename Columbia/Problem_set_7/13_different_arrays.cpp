#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i <n; i++) cin >> a[i];

    int maxi = 300*n;
    vector<int> dp(maxi+1, 0), nxt(maxi+1, 0);

    dp[a[1]] = 1;
    int curr = a[1];

    for (int i =2; i <= n-2; i++) {
        fill(nxt.begin(), nxt.end(), 0);
        int next_max = 0;

        for (int v = 0; v <= curr; v++) {
            if (dp[v] == 0) continue;

            int adder = a[i] +v;
            nxt[adder] += dp[v];
            if (nxt[adder] >= MOD) nxt[adder] -= MOD;
            next_max = max(next_max, adder);

            if (v != 0) {
                int subtracter = abs(a[i] - v);
                nxt[subtracter] += dp[v];
                if (nxt[subtracter] >= MOD) nxt[subtracter] -= MOD;
                next_max = max(next_max, subtracter);
            }
        }

        dp.swap(nxt);
        curr = next_max;
    }

    int ans = 0;
    for (int v = 0; v <= curr; v++) {
        if (dp[v] == 0) continue;
        if (v == 0) {
            ans += dp[v];
        } else {
            ans += dp[v];
            if (ans >= MOD) ans -= MOD;
            ans += dp[v];
        }
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
    return 0;
}