#include <bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    if(n <= 1) return 0; // already at that index.
    if(nums[0] == 0) return -1; // we can never reach the end.

    int jumps = 1; // taken the first jump
    int maxReach = nums[0];
    let steps = nums[0]; // steps still left

    for(int i = 1; i < n; i++) {
        if(i == n-1) {
            cout << jumps << endl; // reached the end.
            return;
        }

        // decrease the no. of steps
        steps--;

        // calculate the new maxReach
        maxReach = max(maxReach, i+nums[i]);
        
        if(steps == 0) {
            jumps++;

            if(i >= maxReach) return -1;
            steps = maxReach - i; // remaining no. of steps we can take.
        }
    }



	return 0;
}