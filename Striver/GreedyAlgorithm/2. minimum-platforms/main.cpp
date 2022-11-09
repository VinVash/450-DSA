int findPlatform(int arr[], int dep[], int n) {
	vector<pair<int, int>> times;
	
	for(int i = 0; i < n; i++) {
	    times.push_back(make_pair(arr[i], dep[i]));
	}
	
	sort(times.begin(), times.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int count = 1;
	pq.push(times[0].second);
	
	for(int i = 1; i < n; i++) {
	    if(pq.top() >= times[i].first)
	        count++;
	    else
	        pq.pop();
	        
	   pq.push(times[i].second);
	}
	
	return count;
}