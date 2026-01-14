#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &soldiers, int power) {
	sort(soldiers.begin(), soldiers.end());
	int total = 0;
	int count = 0;

	for(auto s: soldiers) {
		if(s <= power) {
			count++;
			total += s;
		} else {
			break;
		}
	}
	cout << count << " " << total << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	vector<int> soldiers(n);
	for(int i = 0; i < n; i++)
	    cin >> soldiers[i];

	int q; cin >> q;
	vector<int> powers(q);
	for(int i = 0; i < q; i++)
	    cin >> powers[i];

	for(int i = 0; i < q; i++) {
		solve(soldiers, powers[i]);
	}

	return 0;
}
