#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

int largest_digit(int n) {
	int maxi = 0;
	while(n > 0) {
		int x = n % 10;
		n /= 10;

		maxi = max(maxi, x);
	}

	return maxi;
}

int lowest_digit(int n) {
	int mini = 9;
	while(n > 0) {
		int x = n % 10;
		n /= 10;

		mini = min(mini, x);
	}

	return mini;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		int l, r; cin >> l >> r;

		if(r-l >= 100) {
			int x = l / 100;
			int num = x*100 + 90;
			if(num >= l && num <= r)
				cout << num  << endl;
			else
				cout << num + 100 << endl;
		} else {
			int lucky = l;
			int maxi = 0;
			for(int i = l; i <= r; i++) {
				int low = lowest_digit(i);
				int large = largest_digit(i);

				if(large-low >= maxi) {
					maxi = large-low;
					lucky = i;
				}
			}

			cout << lucky << endl;
		}
	}


	return 0;
}