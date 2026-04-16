#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    vector<int> l, u, d;

    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i])) l.push_back(i);
        else if (isupper(s[i])) u.push_back(i);
        else d.push_back(i);
    }
    
    if (l.size() && u.size() && d.size()) {
        // do nothing
    }
    else if (l.empty() && u.empty()) {
        s[0] = 'a';s[1] ='A';
    } else if (l.empty() && d.empty()) {
        s[0] = 'a';s[1]= '1';
    } else if (u.empty() && d.empty()) {
        s[0] = 'A';s[1]= '1';
    }
    else if (l.empty()) {
        s[u.size() >1 ? u[0] :d[0]] ='a';
    } else if (u.empty()) {
        s[l.size()> 1 ? l[0]: d[0]]= 'A';
    } else if (d.empty()) {
        s[l.size()> 1 ? l[0]: u[0]] ='1';
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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

	return 0;

}