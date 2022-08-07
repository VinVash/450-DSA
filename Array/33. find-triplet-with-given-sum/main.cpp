#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(vector<int> &A, int n, int X) {
    sort(A.begin(), A.end());
    int l, r;
    
    for(int i = 0; i < n-2; i++) {
        l = i+1;
        r = n-1;
        
        while(l < r) {
            if(A[l] + A[r] > X - A[i])
                r--;
            else if(A[l] + A[r] < X - A[i])
                l++;
            else
                return true;
        }
    }
    return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    if(find3Numbers(nums, n, x))
    	cout << "Yes, triplet with sum " << x << " is present" << endl;
    else
    	cout << "No such triplet is present" << endl;


	return 0;
}