#include <bits/stdc++.h>
using namespace std;

int doUnion(vector<int> &a, int n, vector<int> &b, int m)  {
    int res = 0;
    int i = 0, j = 0;
    
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            while(a[i] < b[j] && i < n) {
                if(a[i] != a[i+1])
                	res++;
                i++;
            }
        } else if(a[i] > b[j]) {
            while(a[i] > b[j] && j < m) {
            	if(b[j] != b[j+1])
                	res++;
                j++;
            }
        } else {
            res++;
            i++; j++;
        }
    }
    
    while(i < n) {
    	if(a[i] != a[i+1])
        	res++;
        i++;
    }
    while(j < m) {
    	if(b[j] != b[j+1])
        	res++;
        j++;
    }
    
    return res;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;

    vector<int>ans;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while(i<n && j<m) {
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i]==nums2[j])  {
            ans.push_back(nums1[i]);
            i++;
            j++;
        } else if(nums1[i]>nums2[j])
            j++;
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end()); // unique(ans.begin(), ans.end()) returns the iterator equal to the length of the duplicate removed 'ans' vector.
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n = 0, m = 0;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
		cin >> b[i];

	int res = doUnion(a, n, b, m);
	cout << res << endl;

	return 0;
}