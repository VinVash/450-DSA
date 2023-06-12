#include <bits/stdc++.h>
using namespace std;

// Exponential
int solve(vector<int> coins, int amount) {
    if(amount == 0)
        return 0;
    if(amount < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0; i < coins.size(); i++) {
        int ans = solve(coins, amount-coins[i]);

        if(ans != INT_MAX)
            mini = min(ans+1, mini);
    }

    return mini;
}

// O(x * n) x -> amount, n -> no. of coins.
int solveMem(vector<int> coins, int amount, vector<int>& dp) {
    if(amount == 0)
        return 0;
    if(amount < 0)
        return INT_MAX;

    if(dp[amount] != -1)
        return dp[amount];

    int mini = INT_MAX;

    for(int i = 0; i < coins.size(); i++) {
        int ans = solveMem(coins, amount-coins[i], dp);

        if(ans != INT_MAX)
            mini = min(ans+1, mini);
    }

    return dp[amount] = mini;
}

// O(x * n) x -> amount, n -> no. of coins.
int solveTab(vector<int> coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                int ans = dp[i - coins[j]];
                dp[i] = min(ans+1, dp[i]);
            }
        }
    }

    if(dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> num {1, 2, 5};
    int x =11;


	int ans = solveTab(num, x);
	if(ans == INT_MAX)
		ans = -1;

	cout << "Now the ans is: " << ans << endl;




	return 0;
}