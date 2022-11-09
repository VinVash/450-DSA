#include <bits/stdc++.h>
using namespace std;

// sorting in the decreasing order of profit.
bool compare(vector<int> &job1, vector<int> &job2) {
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs) {

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a slots array of size maxDeadline + 1.
    bool slots[maxDeadline + 1];

    // Initialize the array to false initially.
    for (int i = 0; i <= maxDeadline; i++)
    {
        slots[i] = false;
    }

    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {

            if (slots[j] == false)
            {
                maxProfit = maxProfit + jobs[i][1];
                slots[j] = true;
                break;
            }
        }
    }

    return maxProfit;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int r, c;
	cin >> r >> c;
	
	vector<vector<int>> matrix(r, vector<int>(c, 0));
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
			cin >> matrix[i][j];
	}

	int ans = jobScheduling(matrix);
	cout << ans << endl;

	return 0;
}