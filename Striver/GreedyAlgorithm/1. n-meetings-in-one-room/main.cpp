#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n) {
    int count = 0;
    
    vector<pair<int, int>> times;
    
    for(int i = 0; i < n; i++) {
        times.push_back(make_pair(start[i], end[i]));
    }
    
    sort(times.begin(), times.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    for(auto i: times)
    	cout << i.first << " " << i.second << endl;
    
    int limit = 0;
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        if(times[i].first > limit) {
            limit = times[i].second;
            ans++;
        }
    }
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
	int start[n], end[n];

	for(int i = 0; i < n; i++)
	    cin >> start[i];

	for(int i = 0; i < n; i++)
	    cin >> end[i];

	int ans = maxMeetings(start, end, n);
	cout << ans << endl;

	return 0;
}