#include <bits/stdc++.h>
using namespace std;

// n! / (n-k)!
int permutationCoefficient(int n, int k) {
	int p = 1;

	for(int i = 0; i < k; i++)
		p *= (n-i);

	return p;
}

int permutationCoefficientDP(int n, int k) {
	vector<int> fact(n+1);

	fact[0] = 1;

	for(int i = 1; i <= n; i++)
		fact[i] = i * fact[i-1];

	return fact[n] / fact[n-k];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;

	cout << permutationCoefficient(n, k) << endl;

	return 0;
}