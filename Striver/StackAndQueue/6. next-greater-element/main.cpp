#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int num = nums[i];

        for (int j = 1; j <= n; j++)
        {
            if (nums[(i + j) % n] > num)
            {
                cout << "Found " << nums[(i + j) % n] << " for " << num << endl;
                ans[i] = nums[(i + j) % n];
                break;
            }
        }
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[i] = x;
    }

    vector<int> ans = nextGreaterElements(nums);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}