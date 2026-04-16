#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    
    vector<ll> a(n);
    vector<ll> pref(n+1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }

    ll ans = 0;
    for (ll bit = 60; bit >= 0; bit--) {
        ll tar = ans | (1LL << bit);
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
        dp[0][0] = true;

        for (int i =1; i <=n; i++) {
            for (int j =1; j <=k; j++) {
                for (int m= 0; m< i; m++) {
                    if (dp[m][j-1]) {
                        ll sum = pref[i] - pref[m];
                        if ((sum & tar) == tar) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        if (dp[n][k]) {
            ans = tar;
        }
    }
    
    cout << ans << endl;
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

    solve();

    return 0;
}