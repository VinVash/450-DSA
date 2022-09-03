#include <bits/stdc++.h>
using namespace std;

struct Item {
	int value;
	int weight;
};

bool cmp(pair<double, int> &a, pair<double, int> &b) {
    return a.first > b.first;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    vector<pair<double, int>> percentage;
    
    for(int i = 0; i < n; i++) {
        double per = double(arr[i].value) / arr[i].weight;
        percentage.push_back(make_pair(per, i));
    }
    
    sort(percentage.begin(), percentage.end(), cmp);

    // for(int i = 0; i < n; i++) {
    // 	cout << percentage[i].first << " " << percentage[i].second << endl;
    // }
    
    double val = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[percentage[i].second].weight >= W) {
            val += percentage[i].first * W;
            W = 0;
            break;
        }
        
        val += percentage[i].first * arr[percentage[i].second].weight;
        W -= arr[percentage[i].second].weight;
    }
    
    return val;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n = 3;
	Item arr[3];

	for(int i = 0; i < n; i++) {
		cin >> arr[i].value >> arr[i].weight;
	}

	cout << fractionalKnapsack(50, arr, n) << endl;

	return 0;
}