#include <bits/stdc++.h>
using namespace std;

void organiseTournament(int n, int t) {
	if(n <= 1 || t <= 0)
		return -1;

	int minutes = t * 60;
	int max_matches = n-1;
	int max_time = max_matches * 30; // since each match lasts 30 minutes.

	if(max_time <= minutes) {
		cout << "Possible" << endl;
		return;
	}

	int min_matches = n / 2;
	min_matches = n - min_matches;
	int min_time = min_matches * 30;

	if(min_time <= minutes) {
		cout << "Possible" << endl;
		return;
	}

	cout << "Not possible" << endl;
	return;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}