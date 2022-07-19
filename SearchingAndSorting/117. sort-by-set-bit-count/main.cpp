#include <bits/stdc++.h>
using namespace std;

int countBits(int n) {
	int count = 0;
	while(n) {
		if(n & 1)
			count += 1;
		n = n >> 1;
	}
	
	return count;
}

int cmp(int a, int b) {
    int count1 = countBits(a);
    int count2 = countBits(b);
 
    // this takes care of the stability of sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
}

void sortBySetBitCount(vector<int> &arr, vector<int> &aux, int n) {
	for(int i = 1; i < n; i++) {
		int key1 = aux[i];
		int key2 = arr[i];
		int j = i - 1;

		while(j >= 0 && aux[j] < key1) {
			aux[j+1] = aux[j];
			arr[j+1] = arr[j];
			j = j - 1;
		}

		aux[j+1] = key1;
		arr[j+1] = key2;
	}
}

void sortBySetBitCount2(vector<int> &arr) {
	int n = arr.size();
	stable_sort(arr.begin(), arr.end(), cmp);	
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> aux(n);
    for (int i = 0; i < n; i++) {
    	aux[i] = countBits(arr[i]);
    }

    cout << "Set bit array (aux) : " << endl;
    for(int i = 0; i < aux.size(); i++)
    	cout << aux[i] << " ";
    cout << "-----------------------" << endl;
    cout << endl;

    // sortBySetBitCount(arr, aux, n);
    sortBySetBitCount2(arr);

    for(int i = 0; i < arr.size(); i++)
    	cout << arr[i] << " ";
    cout << endl;

	return 0;
}