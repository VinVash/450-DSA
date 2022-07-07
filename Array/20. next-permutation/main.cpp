#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
  int n = nums.size();
  int i, j; // the indices which need to be swapped.
  
  for(i = n-2; i >= 0; i--) {
    if(nums[i] < nums[i+1])
      break;
  }
//       i has the index where the flow is breaking.
  
  if(i < 0) {
    reverse(nums.begin(), nums.end());
  } else {
    for(j = n-1; j > i; j--) {
      if(nums[j] > nums[i])
        break;
    }
    //       j has the index which needs to be swapped with i.
    swap(nums[i], nums[j]);
    reverse(nums.begin()+i+1, nums.end());
  }
  
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums {5, 3, 2, 4, 1};
    nextPermutation(nums);

    for(int i = 0; i < nums.size(); i++)
    	cout << nums[i] << " ";
    cout << endl;


	return 0;
}