#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;



int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<pair<int, int>> requests(n);
    for(int i=0; i<n; i++) {
        cin >> requests[i].first >> requests[i].second;
    }

    int max_packets, rate;
    cin >> max_packets >> rate;

    // sort the requests by time
    sort(requests.begin(), requests.end());

    // priority queue to store the packets
    priority_queue<int> pq;
    int dropped = 0, prev_time = 0;

    for(auto& req : requests) {
        // deliver packets before current request arrives
        while(!pq.empty() && prev_time < req.first) {
            int deliver = min(rate, (int)pq.size());
            for(int i=0; i<deliver; i++) pq.pop();
            prev_time++;
        }

        // add current request's packets into the queue
        for(int i=0; i<req.second; i++) pq.push(1);

        // if the queue size exceeds max_packets, count the excess packets as dropped
        while((int)pq.size() > max_packets) {
            pq.pop();
            dropped++;
        }

        prev_time = req.first;
    }

    // deliver remaining packets
    while(!pq.empty()) {
        int deliver = min(rate, (int)pq.size());
        for(int i=0; i<deliver; i++) pq.pop();
        prev_time++;
    }

    cout << dropped << endl;


    return 0;
}