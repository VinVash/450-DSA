#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;

	// int ch = t[0];
	// vector<int> pos;

	// for(int i = 0; i < s.size(); i++) {
	// 	if(s[i] == ch) pos.push_back(i);
	// }

	// bool found = false;
	// for(int idx: pos) {
		
	// 	// try to go right
	// 	int j = 0;
	// 	while(idx < s.size() && j < t.size() && s[idx] == t[j]) {
	// 		idx++;
	// 		j++;
	// 	}
		
	// 	idx -= 2;

	// 	// try to go right
	// 	while(idx >= 0 && j < t.size() && s[idx] && s[idx] == t[j]) {
	// 		idx--;
	// 		j++;
	// 	}

	// 	if(j == t.size()) {
	// 		cout << "YES" << endl;
	// 		found = true;
	// 		return;
	// 	}

	// }
	// if(!found) {
	// 	cout << "NO" << endl;
	// }

	int n = s.size();
    int m = t.size();

    // i is the starting position in s
    for (int i = 0; i < n; i++) {
        // j is the pivot position (where we turn left)
        for (int j = i; j < n; j++) {
            string current = "";
            bool possible = true;
            
            // 1. Move Right from i to j
            int t_idx = 0;
            for (int k = i; k <= j && t_idx < m; k++) {
                if (s[k] == t[t_idx]) {
                    t_idx++;
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;
            if (t_idx == m) {
            	cout << "YES" << endl;
            	return;
            }

            // 2. Move Left from j-1 downwards
            for (int k = j - 1; k >= 0 && t_idx < m; k--) {
                if (s[k] == t[t_idx]) {
                    t_idx++;
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible && t_idx == m) {
            	cout << "YES" << endl;
            	return;
            }
        }
    }
    
    cout << "NO" << endl;

}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
    	solve();
    }

    return 0;
}