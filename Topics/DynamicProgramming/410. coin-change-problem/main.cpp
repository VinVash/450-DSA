#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &S, int m, int n) {
	vector<int> table(n+1, 0);
	 
	table[0] = 1;         
	// Pick all coins one by one and update the table[] values
	// after the index greater than or equal to the value of the
	// picked coin
	for(int i = 0; i < m; i++) {
		for(int j = S[i]; j <= n; j++)
			table[j] += table[j - S[i]];
	}
	return table[n];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}