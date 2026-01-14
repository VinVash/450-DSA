#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &books, int n, int m, int minn) {
	int studentsRequired = 1;
	int curr_sum = 0;

	for(int i = 0; i < n; i++) {
		if(books[i] > minn)
			return false;

		if(curr_sum + books[i] > minn) {
			studentsRequired++;

			curr_sum = books[i];

			if(studentsRequired > m)
				return false;
		} else {
			curr_sum += books[i];
		}
	}

	return true;
}

int solve(vector<int> &books, int n, int m) {
	int sum = 0;

	if(n < m) return -1; // since there are more students than the books.

	// count total number of pages.
	for(auto i: books)
		sum += i;

	int low = 0, high = sum;
	int result = INT_MAX;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(isPossible(books, n, m, mid)) {
			result = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return result;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	vector<int> books(n);

	for(int i = 0; i < n; i++)
	    cin >> books[i];

	cout << solve(books, n, m) << endl;

	return 0;
}