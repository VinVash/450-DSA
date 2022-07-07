#include <bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2){
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  int n = intervals.size();
  vector<vector<int>> res;

  if(n <= 1) return intervals;

  sort(intervals.begin(), intervals.end(), sortcol);
  
  for (int i = 0; i < n-1; i++) {
    vector<int> temp(2);
    temp[0] = intervals[i][0];
    temp[1] = intervals[i][1];
    while(i+1 < n && intervals[i+1][0] <= intervals[i][1]) {
      temp[1] = intervals[i+1][1];
      i++;
    }
    res.push_back(temp);
  }
  
  if(intervals[n-1][1] != res[res.size()-1][1])
    res.push_back(intervals[n-1]);
  
  return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int>> intervals;
	intervals.push_back({1, 4});
	intervals.push_back({0, 4});
	// intervals.push_back({4, 5});

	vector<vector<int>> res = merge(intervals);

	for(int i = 0; i < res.size(); i++)
		cout << res[i][0] << " " << res[i][1] << endl;


	return 0;
}