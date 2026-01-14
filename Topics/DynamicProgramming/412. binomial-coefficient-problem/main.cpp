#include <bits/stdc++.h>
using namespace std;

int binomailCoefficient(int n, int k) {
	vector<int> C(n+1, 0);

	C[0] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = min(i, k); j > 0; j--) {
			C[j] = C[j] + C[j-1];
		}
	}

	return C[k];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;

	cout << binomailCoefficient(n, k) << endl;

	return 0;
}