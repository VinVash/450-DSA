#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct D {
    vector<int> p,r;
    D(int n) {
        p.resize(n+1);
        r.assign(n+1, 0);
        for (int i =1; i <=n; i++) p[i] =i;
    }
    int f(int x) {
        if (p[x] == x) return x;
        return p[x] = f(p[x]);
    }
    bool u(int a, int b) {
        a = f(a); b = f(b);

        if (a ==b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] =a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m+1), y(m+1), ok(m+1, 0);
    vector<vector<int>> g(n+1);
    D d(n);
    for (int i=1; i <=m; i++) {
        cin >> x[i] >> y[i];
        if (d.u(x[i], y[i])) {
            ok[i] =1;
            g[x[i]].push_back(y[i]);
            g[y[i]].push_back(x[i]);
        }
    }

    int lg =1;
    while ((1 << lg) <=n) lg++;
    vector<vector<int>> up(lg, vector<int>(n+1, 0));
    vector<int> dep(n+1, 0), tin(n+1, 0), tout(n+1, 0), ord;
    ord.reserve(n);
    int tim = 0;

    vector<array<int, 3>> st;
    st.push_back({1, 0, 0});
    while (!st.empty()) {
        auto cur = st.back();
        st.pop_back();
        int u = cur[0], p = cur[1], t = cur[2];
        if (t == 0) {
            up[0][u] = p;
            tin[u] = tim;
            ord.push_back(u);
            tim++;
            st.push_back({u, p, 1});
            for (int i = (int)g[u].size()-1; i >=0; i--) {
                int v = g[u][i];
                if (v == p) continue;
                dep[v] = dep[u]+1;
                st.push_back({v, u, 0});
            }
        } else {
            tout[u] = tim-1;
        }
    }

    for (int j = 1; j <lg; j++) {
        for (int i =1; i <= n; i++) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }

    auto anc = [&](int a, int b) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    };

    auto jp = [&](int u, int k) {
        for (int j = 0; j < lg; j++) {
            if ((k >> j) & 1) u = up[j][u];
        }
        return u;
    };

    vector<ll> ad(n+1, 0);
    ll gl = 0;

    auto addsub = [&](int v, ll val) {
        ad[tin[v]] += val;
        ad[tout[v] + 1] -= val;
    };

    auto addcomp = [&](int v, int tp, ll val) {
        if (tp == 0) {
            addsub(v, val);
        } else {
            gl +=val;
            addsub(v, -val);
        }
    };

    for (int i = 1; i <= m; i++) {
        if (ok[i]) continue;
        int a = x[i], b = y[i];
        int va, ta, vb, tb;

        if (anc(a, b)) {
            int c = jp(b, dep[b] - dep[a] - 1);
            va = c;
            ta = 1;
        } else {
            va = a;
            ta = 0;
        }

        if (anc(b, a)) {
            int c = jp(a, dep[a] - dep[b] - 1);
            vb = c;
            tb = 1;
        } else {
            vb = b;
            tb = 0;
        }

        gl++;
        addcomp(va, ta, -1);
        addcomp(vb, tb, -1);
    }

    vector<ll> bad(n + 1, 0);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += ad[i];
        int u = ord[i];
        bad[u] = cur + gl;
    }

    string s;
    s.reserve(n);
    for (int i = 1; i <= n; i++) {
        if (bad[i] == 0) s.push_back('1');
        else s.push_back('0');
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}
