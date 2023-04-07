#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
	int n = height.size();
	int l = 0, r = n-1;
	int ans = 0;

	while(l < r) {
		int h = min(height[l], height[r]);
		int width = r-l;
		int area = h * width;
		ans = max(ans, area);

		if(height[l] <= height[r])
			l++;
		else
			r--;
	}

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}