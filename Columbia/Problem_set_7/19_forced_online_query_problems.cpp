#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct D {
    int n;
    vector<int> p, r;
    D() {}
    D(int n) { init(n); }
    void init(int n2) {
        n = n2;
        p.resize(n+1);
        r.assign(n+1, 0);
        for (int i =1; i <=n; i++) p[i] =i;
    }
    int f(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
};

struct Q {
    int t, x, y;
};

struct TD {
    vector<int> p, r;
    void init(int n) {
        p.resize(n);
        r.assign(n, 0);
        for (int i =0; i <n; i++) p[i] =i;
    }
    int f(int x) {
        while (p[x] !=x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
};

ll enc(int a, int b) {
    if (a > b) swap(a, b);
    return (ll(a) << 32) ^ll(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<Q> q(m);
    for (int i = 0; i <m; i++) cin >> q[i].t >> q[i].x >> q[i].y;

    auto inc = [&](int x) {
        if (x == n) return 1;
        return x+1;
    };

    const int b =350;
    unordered_set<ll> st;
    st.reserve(m*2 + 10);
    st.max_load_factor(0.7);

    int last = 0;
    string ans;
    ans.reserve(m);

    for (int l = 0; l <m; l +=b) {
        int r = min(m -1, l+b-1);

        unordered_map<ll, int> id;
        id.reserve((r-l+1) * 4 + 10);
        id.max_load_factor(0.7);

        vector<ll> k;
        vector<int> a, c;

        for (int i = l; i <= r; i++) {
            if (q[i].t != 1) continue;
            int x0 = q[i].x, y0 = q[i].y;
            ll k0 = enc(x0, y0);
            if (!id.count(k0)) {
                int z = (int)k.size();
                id[k0] = z;
                k.push_back(k0);
                a.push_back((int)(k0 >> 32));
                c.push_back((int)(k0 & 4294967295LL));
            }
            int x1 = inc(q[i].x), y1 = inc(q[i].y);
            ll k1 = enc(x1, y1);
            if (!id.count(k1)) {
                int z = (int)k.size();
                id[k1] = z;
                k.push_back(k1);
                a.push_back((int)(k1 >> 32));
                c.push_back((int)(k1 & 4294967295LL));
            }
        }

        int s = (int)k.size();
        vector<char> on(s, 0);
        for (int i = 0; i < s; i++) {
            if (st.find(k[i]) != st.end()) on[i] = 1;
        }

        D d(n);
        for (auto e : st) {
            if (id.count(e)) continue;
            int u = (int)(e >> 32);
            int v = (int)(e & 4294967295LL);
            d.u(u, v);
        }

        vector<int> ra(s), rb(s);
        vector<int> all;
        all.reserve(s * 2);
        for (int i = 0; i < s; i++) {
            ra[i] = d.f(a[i]);
            rb[i] = d.f(c[i]);
            all.push_back(ra[i]);
            all.push_back(rb[i]);
        }
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        vector<int> ea(s), eb(s);
        for (int i = 0; i < s; i++) {
            if (ra[i] == rb[i]) {
                ea[i] = -1;
                eb[i] = -1;
            } else {
                ea[i] = lower_bound(all.begin(), all.end(), ra[i]) - all.begin();
                eb[i] = lower_bound(all.begin(), all.end(), rb[i]) - all.begin();
            }
        }

        TD td;

        for (int i = l; i <= r; i++) {
            int x = q[i].x, y = q[i].y;
            if (last == 1) {
                x = inc(x);
                y = inc(y);
            }

            if (q[i].t == 1) {
                ll kk = enc(x, y);
                int z = id[kk];
                on[z] ^= 1;
                if (on[z]) st.insert(kk);
                else st.erase(kk);
            } else {
                int u = d.f(x), v = d.f(y);
                int out = 0;
                if (u == v) {
                    out = 1;
                } else {
                    int iu = lower_bound(all.begin(), all.end(), u) - all.begin();
                    int iv = lower_bound(all.begin(), all.end(), v) - all.begin();
                    if (iu < (int)all.size() && iv < (int)all.size() && all[iu] == u && all[iv] == v) {
                        td.init((int)all.size());
                        for (int j = 0; j < s; j++) {
                            if (!on[j]) continue;
                            if (ea[j] == -1) continue;
                            td.u(ea[j], eb[j]);
                        }
                        if (td.f(iu) == td.f(iv)) out = 1;
                    }
                }
                if (out) ans.push_back('1');
                else ans.push_back('0');
                last = out;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
