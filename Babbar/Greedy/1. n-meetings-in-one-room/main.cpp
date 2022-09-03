#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

// Time: nlogn
int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;
    
    for(int i = 0; i < n; i++) {
        meetings.push_back(make_pair(start[i], end[i]));
    }
    
    sort(meetings.begin(), meetings.end(), cmp);
    
    int count = 1;
    int ansEnd = meetings[0].second;
    
    for(int i = 1; i < n; i++) {
        if(meetings[i].first > ansEnd) {
            count++;
            ansEnd = meetings[i].second;
        }
    }
    
    return count;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	return 0;
}