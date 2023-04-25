#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

int solve(vi& sec, int val, int index) {

	if(index == sec.size())
		return 0;

	if(val < 0)
		return 0;

	int inc = sec[index] + solve(sec, val-sec[index], index+1);
	int exc = 0 + solve(sec, val, index+1);

	return (inc == val || exc == val);
}

bool check(int l, int r, int val, vi& vec) {
	int sum = 0;

	vi sec(r-l+1);
	for(int i = l; i <= r; i++)
		sec[i-l] = vec[i];

	return solve(sec, val, 0);


}

void solve(vi& vec, int n) {
	sort(vec.begin(), vec.end());

	bool flag = true;
	for(int i = n-1; i >= 1; i--) {
		if(!check(0, i-1, vec[i], vec)) {
			break;
			flag = false;
		}
	}

	if(flag == false)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vi c(n);
		for(int i = 0; i < n; i++)
		    cin >> c[i];

		solve(c, n);
	}


	return 0;
}