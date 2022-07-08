#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int>& arr,int a, int b) {
    int n = arr.size();
    int l = 0, r = n-1;

    for(int i = 0; i <= r;) {
        if(arr[i] >= a && arr[i] <= b) {
            i++;
        } else if(arr[i] > b) {
            swap(arr[i], arr[r]);
            r--;
        } else {
            if(i == l) {
                i++;
                l++;
            } else {
                swap(arr[i], arr[l]);
                l++;
                i++;
            }
        }
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    threeWayPartition(nums, a, b);

    for(int i = 0; i < nums.size(); i++)
    	cout << nums[i] << " ";
    cout << endl;


	return 0;
}