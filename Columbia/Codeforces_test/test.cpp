#include <bits/stdc++.h>
using namespace std;

void solve() {

    long long n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;

    vector<long long> x(n, 0);
    vector<long long> y(n, 0);

    for(long long j = 0; j< n; j++) cin >> x[j];
    for(long long j = 0; j < n; j++) cin >> y[j];

    vector<pair<long long, long long>> points(n);
    for(long long i = 0; i < n; i++) {
        points[i] = { x[i], y[i] };
    }

    sort(points.begin(), points.end());

    long long prev_l = ay, prev_r = ay;
    long long dp_l = 0, dp_r = 0;

    long long i = 0;
    while(i < n) {
        long long curr_x = points[i].first;
        long long curr_ymin = points[i].second;
        long long curr_ymax = points[i].second;

        while(i < n && points[i].first == curr_x) {
            curr_ymin = min(curr_ymin, points[i].second);
            curr_ymax = max(curr_ymax, points[i].second);
            i++;
        }

        long long dist = curr_ymax - curr_ymin;

        long long cost_to_reach_top_entry = min(
            dp_l + abs(prev_l - curr_ymax),
            dp_r + abs(prev_r - curr_ymax)
        );
        long long new_dpl = cost_to_reach_top_entry + dist;

        long long cost_to_reach_bottom_entry = min(
            dp_l + abs(prev_l - curr_ymin),
            dp_r + abs(prev_r - curr_ymin)
        );
        long long new_dpr = cost_to_reach_bottom_entry + dist;

        dp_l = new_dpl;
        dp_r = new_dpr;
        prev_l = curr_ymin;
        prev_r = curr_ymax;
    }

    long long final_cost = min(dp_l + abs(prev_l - by), dp_r + abs(prev_r - by));

    cout << final_cost + (bx - ax) << endl;
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    long long t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}