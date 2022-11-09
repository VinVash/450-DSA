#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount) {
    vector<int> nums {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    
    int i = nums.size()-1; // pointer at the largest denomination.
    int count = 0;
    
    while(amount > 0) {
        if(i == -1)
            break;
        
        if(amount - nums[i] >= 0) {
            amount -= nums[i]; // keep subtracting money.
            count++;   
        } else {
            i--;
        }
    }
    
    return count;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	int ans = findMinimumCoins(n);
	cout << ans << endl;

	return 0;
}