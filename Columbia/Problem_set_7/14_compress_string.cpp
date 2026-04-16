#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s; cin >> s;

    int N = n+1;
    vector<uint16_t> lcp(N*N, 0);
    auto at = [&](int i, int j) -> uint16_t& {
        return lcp[i*N + j];
    };

    for (int i = n-1; i >=0; i--) {
        for (int j = n-1; j >=0; j--) {
            if (s[i] == s[j]) {
                at(i, j) = static_cast<uint16_t>(at(i +1, j +1) + 1);
            }
        }
    }

    vector<int> bestlen(n, 0);
    for (int i = 0; i < n; i++) {
        int best =0;
        for (int j =0; j <i; j++) {
            int common = at(j, i);
            common = min(common, i-j);
            if (common > best) best = common;
        }
        bestlen[i] = best;
    }

    const ll INF = (1LL << 60);
    vector<ll> dp(n+1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        dp[i+1] = min(dp[i+1], dp[i] +a);

        int mx = bestlen[i];
        for (int len = 1; len <= mx; len++) {
            dp[i+len] = min(dp[i+len], dp[i] + b);
        }
    }

    cout << dp[n] << endl;
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
