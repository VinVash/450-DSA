#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int n) {
	vector<int> res(n, 0);

	int max_element = prices[n-1];
	for(int i = n-2; i >= 0; i--) {
		if(prices[i] > max_element)
			max_element = prices[i];

		res[i] = max(res[i+1], max_element - prices[i]);
	}

	int min_element = prices[0];
	for(int i = 1; i < n; i++) {
		if(prices[i] < min_element)
			min_element = prices[i];

		res[i] = max(res[i-1], res[i]+prices[i]-min_element);
	}

	return res[n-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

	cout << maxProfit(prices, prices.size()) << endl;


	return 0;
}