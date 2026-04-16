#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;

    set<char> s1, s2;
    set<char> intersection;

    for(char ch: s) s1.insert(ch);
    for(char ch: t) s2.insert(ch);

    std::set_intersection(
        s1.begin(), s1.end(),
        s2.begin(), s2.end(),
        inserter(intersection, intersection.begin())
    );

    if(intersection.size()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

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