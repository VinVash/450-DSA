#include <bits/stdc++.h>
using namespace std;

int carAssembly(vector<vector<int>> &a, vector<vector<int>> &t, vector<int> &e, vector<int> &x) {
	int n = a[0].size();

	vector<int> t1(n), t2(n);
	int i;

	t1[0] = e[0] + a[0][0];
	t2[0] = e[1] + a[1][0];

	for(i = 1; i < 4; i++) {
		t1[i] = min(t1[i-1] + a[0][i], t2[i-1] + t[1][i] + a[0][i]);
		t2[i] = min(t2[i-1] + a[1][i], t1[i-1] + t[0][i] + a[1][i]);
	}

	return min(t1[n-1] + x[0], t2[n-1] + x[1]);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<vector<int>> a {{4, 5, 3, 2},
						   {2, 10, 1, 4}};

	vector<vector<int>> t {{0, 7, 4, 5},
						   {0, 9, 2, 8}};

	vector<int> e {10, 12};
	vector<int> x {18, 7};

	cout << carAssembly(a, t, e, x) << endl;

	return 0;
}