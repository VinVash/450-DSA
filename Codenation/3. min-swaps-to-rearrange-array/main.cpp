#include <bits/stdc++.h>
using namespace std;

int countMinSwaps(vector<int> &arr, int n) {
	int index_mod_0 = 0, index_mod_1 = 0, index_mod_2 = 0;
	int array_mod_0 = 0, array_mod_1 = 0, array_mod_2 = 0;

	int i, j, count = 0;

	for(i = 0; i < n; i++) {
		if(i % 3 == 0)
			index_mod_0++;
		else if(i % 3 == 1)
			index_mod_1++;
		else
			index_mod_2++;

		if(arr[i] % 3 == 0)
			array_mod_0++;
		else if(arr[i] % 3 == 1)
			array_mod_1++;
		else
			array_mod_2++;
	}

	if(index_mod_0 != array_mod_0 || index_mod_1 != array_mod_1 || index_mod_2 != array_mod_2)
		return -1;

	for(i = 0; i < n; i++) {
		int index_og = i % 3;
		int array_og = arr[i] % 3;

		if(index_og == array_og)
			continue;

		bool swapped = false;

		for(int j = i+1; j < n; j++) {
			int index_exp = j % 3;
			int array_exp = arr[j] % 3;

			if(index_og == array_exp && array_og == index_exp) {
				swap(arr[i], arr[j]);
				swapped = true;
				count += 1;
				break;
			}
		}

		if(!swapped) {
			for(j = i+1; j < n; j++) {
				int array_exp = arr[j] % 3;
				if(index_og == array_exp) {
					swap(arr[i], arr[j]);
					count += 1;
					break;
				}
			}
		}
	}

	return count;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr { 4, 3, 5, 2, 9, 7 };

	cout << countMinSwaps(arr, arr.size()) << endl;

	return 0;
}