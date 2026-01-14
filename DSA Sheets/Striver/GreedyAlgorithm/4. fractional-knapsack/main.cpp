static bool cmp(pair<double, int> &a, pair<double, int> &b) {
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