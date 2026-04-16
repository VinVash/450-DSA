#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, n; cin >> h >> n;
	vector<int> a(n);
	for(int i = 0; i <n; i++) cin >> a[i];

	int i = 0;
	int count = 0;
	while (i < n-1) {

        int landing = a[i+1] - 1;
        if (landing == 0) {
            break;
        }
        
        if (i+2 < n && a[i+2] == landing) {
            i += 2;
        } else {
            count++;
            i += 1;
        }
    }

    cout << count << endl;

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