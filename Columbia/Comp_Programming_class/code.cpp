#include <bits/stdc++.h>
using namespace std;

void check(string s) {
    cout << "Inside check" << endl;
    s += s;
    for(char ch: s) cout << ch << " ";
    cout << endl;

    // no. of cyclic shifts

    int n = s.size();
    int m = n/2; // original size
    vector<int> pre(n);
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            pre[i] = ++count;
        } else {
            pre[i] = --count;
        }
    }
    for(int x: pre) cout << x << " ";
    cout << endl;

    vector<int> fl(m);
    int mini = INT_MAX;
    for(int i = 0; i < m; i++) {
        mini = min(mini, pre[i]);
        fl[i] = mini;
    }

    vector<int> fr(m);
    mini = INT_MAX;
    for(int i = m-1; i >= 0; i--) {
        mini = min(mini, pre[i]);
        fr[i] = mini;
    }

    vector<int> sl(m);
    mini = INT_MAX;
    for(int i = m; i < n; i++) {
        mini = min(mini, pre[i]);
        sl[i] = mini;
    }

    vector<int> sr(m);
    mini = INT_MAX;
    for(int i = n-1; i >= m; i--) {
        mini = min(mini, pre[i]);
        fr[i] = mini;
    }

    cout << "---------------------------" << endl;

    int count_valid = 0;
    for(int i = 0; i < m; i++) {
        int l = i, r = i;

        int mini = min(fr[i], sl[i]);
        int match = 0;
        if(i == 0) match = 0;
        else match = pre[i-1];

        if(mini >= match) {
            count_valid++;
        } else {
            continue;
        }
    }

    cout << count_valid << endl;
}

void solve() {
	int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i< n-1; i++) {
        for(int j = i+1; j < n; j++) {
            swap(s[i], s[j]);
            cout << i << " " << j << endl;
            cout << "Original string" << endl;
            for(char ch: s) cout << ch << " ";
            cout << endl;
            check(s);
            swap(s[i], s[j]);
        }
    }
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

// -----------------------------------------

int solve(const string &s) {
    int n = (int)s.size();
    string t = s + s;
    int m = 2 * n;

    vector<int> presum(m);
    presum[0] = (t[0] == '(' ? 1 : -1);
    for (int i = 1; i < m; ++i)
        presum[i] = presum[i - 1] + (t[i] == '(' ? 1 : -1);

    vector<int> minl(m), minr(m);
    minl[0] = presum[0];
    for (int i = 1; i < m; ++i)
        minl[i] = min(minl[i - 1], presum[i]);

    minr[m - 1] = presum[m - 1];
    for (int i = m - 2; i >= 0; --i)
        minr[i] = min(minr[i + 1], presum[i]);

    int cnt = 0;
    for (int k = 0; k < n; ++k) {
        int L = k;
        int R = k + n - 1;
        int base = (L == 0 ? 0 : presum[L - 1]);

        int min_in_range;
        if (L == 0)
            min_in_range = minl[R];
        else
            min_in_range = min(minl[R], minr[L]);

        int end_val = presum[R] - base;
        if (end_val == 0 && min_in_range - base >= 0)
            cnt++;
    }
    return cnt;
}

int main() {
    int n;
    string s;
    if (!(cin >> n)) return 0;
    cin >> s;

    int best = solve(s);
    int rx = 0, ry = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string t = s;
            swap(t[i], t[j]);
            int cur = solve(t);
            if (cur > best) {
                best = cur;
                rx = i;
                ry = j;
            }
        }
    }

    cout << best << endl;
    cout << rx + 1 << " " << ry + 1 << endl;
    return 0;
}