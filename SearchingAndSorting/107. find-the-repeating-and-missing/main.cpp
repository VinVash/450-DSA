#include <bits/stdc++.h>
using namespace std;

void getTwoElements(vector<int> &arr, int n) {
	int repeating = 0, missing = 0;
	int i = 0;

	while(i < n) {
		if(arr[i] == arr[arr[i]-1])
			i++;
		else
			swap(arr[i], arr[arr[i]-1]);
	}

	for(int i = 0; i < n; i++) {
		if(arr[i] != i+1) {
			repeating = arr[i];
			missing = i+1;
			break;
		}
	}

	cout << repeating << " " << missing << endl;
}

void getTwoElements2(vector<int> &arr, int n) {
	int repeating = 0, missing = 0;

	for(int i = 0; i < n; i++) {
		if(arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		else
			repeating = abs(arr[i]);
	}

	for(int i = 0; i < n; i++) {
		if(arr[i] > 0)
			missing = i+1;
	}

	cout << repeating << " " << missing << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	vector<int> nums(n);

	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	getTwoElements(nums, n);
	getTwoElements2(nums, n);

	return 0;
}