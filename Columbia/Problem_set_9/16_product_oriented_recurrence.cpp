#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m1 = 1000000007;
ll m2 = 1000000006;

struct Mat {
    ll m[5][5];
    Mat() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                m[i][j] = 0;
            }
        }
    }
};

Mat mul(Mat a, Mat b) {
    Mat res;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % m2;
            }
        }
    }
    return res;
}

Mat power(Mat a, ll b) {
    Mat res;
    for (int i = 0; i < 5; i++) {
        res.m[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll bp(ll a, ll b) {
    ll res = 1;
    a %= m1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m1;
        a = (a * a) % m1;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    Mat t;
    t.m[0][0] = 1; t.m[0][1] = 1; t.m[0][2] = 1; t.m[0][3] = 2; t.m[0][4] = m2 - 4;
    t.m[1][0] = 1;
    t.m[2][1] = 1;
    t.m[3][3] = 1; t.m[3][4] = 1;
    t.m[4][4] = 1;

    Mat res = power(t, n-3);

    ll p3 = res.m[0][0];
    ll p2 = res.m[0][1];
    ll p1 = res.m[0][2];
    ll pc = (res.m[0][3]*3 + res.m[0][4]) % m2;

    ll ans = 1;
    ans = (ans * bp(f3, p3)) % m1;
    ans = (ans * bp(f2, p2)) % m1;
    ans = (ans * bp(f1, p1)) % m1;
    ans = (ans * bp(c, pc)) % m1;

    cout << ans << endl;

    return 0;
}