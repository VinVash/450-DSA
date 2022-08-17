#include <bits/stdc++.h>
using namespace std;

 int maxProfit(vector<int> &prices) {
 	int mini = prices[0];
 	int profit = 0;

 	for(int i=1; i < n; i++) {
 		int diff = prices[i] - mini;
 		profit = max(profit, diff);
 		mini = min(mini, prices[i]);
 	}

 	return profit;
 }

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}