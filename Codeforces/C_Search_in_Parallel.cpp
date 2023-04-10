#include <bits/stdc++.h>
using namespace std;

bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

void solve(vector<pair<int, int>>& boxes, int n, int s1, int s2) {
	int i = 1;
	int index = 0;

	// for(auto x: boxes)
	// 	cout << x.second << " ";
	// cout << endl;

	vector<int> a, b;

	while(index < n) {
		if(i % s1 == 0) {
			a.push_back(boxes[index].second);
			index++;
		}
		if(i % s2 == 0) {
			if(index < n) {
				b.push_back(boxes[index].second);
				index++;
			}
		}
		i++;
	}


	cout << a.size() << " ";
	for(auto x: a)
		cout << x << " ";
	cout << endl;

	cout << b.size() << " ";
	for(auto x: b)
		cout << x << " ";
	cout << endl;

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int t; cin >> t;
    while(t--) {
    	int n, s1, s2; cin >> n >> s1 >> s2;
    	vector<pair<int, int>> boxes;
    	for(int i = 0; i < n; i++) {
    		int x; cin >> x;
    		boxes.push_back({ x, i+1 });
    	}

    	sort(boxes.begin(), boxes.end(), comparator);

    	solve(boxes, n, s1, s2);

    }

	return 0;
}