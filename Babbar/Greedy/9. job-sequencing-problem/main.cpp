#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) { 
    sort(arr, arr+n, cmp);
    
    int maxDeadline = INT_MIN;
    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }
    
    vector<int> schedule(maxDeadline+1, -1);
    
    int count = 0;
    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        int currProfit = arr[i].profit;
        int currJobID = arr[i].id;
        int currDeadline = arr[i].dead;
        
        for(int k = currDeadline; k > 0; k--) {
            if(schedule[k] == -1) {
                count++;
                maxProfit += currProfit;
                schedule[k] = currJobID;
                break;
            }
        }
    }
    
    vector<int> res;
    res.push_back(count);
    res.push_back(maxProfit);
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}