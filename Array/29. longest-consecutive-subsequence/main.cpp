#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(vector<int> &arr, int N) {
  sort(arr.begin(), arr.end());
  set<int> unique;
  
  for(int i = 0; i < N; i++)
    unique.insert(arr[i]);
    
  vector<int> ans(unique.begin(), unique.end());
  int n = ans.size();
  
  int res = 0;
  
  int temp = 1;
  
  for(int i = 0; i < n-1; i++) {
      while(ans[i+1] - ans[i] == 1 && i+1 <= n-1) {
        temp++;
        i++;
      }
      res = max(res, temp);
      temp = 1;
  }
  
  if(res == 0) res = 1; // since 1 element is always consecutive.
  
  return res;
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

	cout << findLongestConseqSubseq(nums, n) << endl;

	return 0;
}