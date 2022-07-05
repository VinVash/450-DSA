#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
  int tortoise = nums[0];
  int hare = nums[0];
  
  do {
    tortoise = nums[tortoise];
    hare = nums[nums[hare]];
  } while (tortoise != hare);
  
  tortoise = nums[0];
  while(tortoise != hare) {
    tortoise = nums[tortoise];
    hare = nums[hare];
  }
  
  return hare;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums {2, 6, 4, 1, 3, 1, 5};
	cout << findDuplicate(nums) << endl;


	return 0;
}