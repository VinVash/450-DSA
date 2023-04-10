#include <bits/stdc++.h>
using namespace std;



int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;

	while(t--) {
		int n, x1, y1, x2, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;

		int mid = n/2;
		int midder = mid+1;

		int dx1 = (x1 <= mid) ? x1-mid : x1-midder;
		int dy1 = (y1 <= mid) ? y1-mid : y1-midder;
		int dx2 = (x2 <= mid) ? x2-mid : x2-midder;
		int dy2 = (y2 <= mid) ? y2-mid : y2-midder;

		int max1 = max(abs(dx1), abs(dy1));
		int max2 = max(abs(dx2), abs(dy2));

		cout << abs(max1 - max2) << endl;
	}


	return 0;
}