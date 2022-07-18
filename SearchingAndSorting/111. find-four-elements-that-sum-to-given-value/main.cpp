#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n; i++)
    {
        int j=i+1,k=n-1;//two pointers
        while(j<n && j<k)
        {
            if(nums[j]+nums[k] == -nums[i] + target)
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                while(k!=0 && nums[k]==nums[k-1]) k--;//to avoid duplicates 
                while(j!=n-1 && nums[j]==nums[j+1]) j++;
                j++,k--;
            }
            else if(nums[j]+nums[k] > -nums[i] + target) 
            {
                while(k!=0 && nums[k]==nums[k-1]) k--;
                k--;
            }
            else
            {
                while(j!=n-1 && nums[j]==nums[j+1]) j++;
                j++;
            }
        }
        while(i!=n-1 && nums[i]==nums[i+1]) i++;
    }
    for(auto triplet : ans)
        sort(triplet.begin(),triplet.end());
    return ans;
}

// This is O(n^3) function.
vector<vector<int>> fourSum(vector<int> &arr, int k) {
	int n = arr.size();
	vector<vector<int>> res;

	int i = 0 ;
	while(i < n-3) {
		vector<int> temper = vector<int>(arr.begin()+i+1, arr.end());
		vector<vector<int>> temp = threeSum(temper, k-arr[i]);

		for(auto triplet: temp) {
			triplet.push_back(arr[i]);
			res.push_back(triplet);
		}

		while(i != n-1 && arr[i+1] == arr[i]) i++;
		i++;
	}

	return res;
}

// This is O(n^3) function.
void find4Numbers(vector<int> &arr, int n, int X) {
    int l, r;

    sort(arr.begin(), arr.end());
 
    /* Now fix the first 2 elements one by one and find the other two elements */
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i+1; j < n - 2; j++)
        {
            // Initialize two variables as
            // indexes of the first and last
            // elements in the remaining elements
            l = j + 1;
            r = n-1;
 
            // To find the remaining two elements, move the index
            // variables (l & r) toward each other.
            while (l < r)
            {
                if( arr[i] + arr[j] + arr[l] + arr[r] == X)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[l] << " " << arr[r];
                    l++; r--;
                }
                else if (arr[i] + arr[j] + arr[l] + arr[r] < X)
                    l++;
                else
                    r--;
            }
        }
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;

	vector<int> nums(n);
	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	vector<vector<int>> res = fourSum(nums, k);

	for(auto vec: res) {
		for(auto i : vec)
			cout << i << " ";
		cout << endl;
	}

	// find4Numbers(nums, n, k);

	return 0;
}