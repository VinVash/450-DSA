#include <bits/stdc++.h>
using namespace std;

void task(int id) {
    cout << "Task " << id << " start\n";

    if (id == 1) {
        task(2);
        task(4);
    } else if (id == 2) {
        task(3);
    }

    cout << "Task " << id << " end\n";
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    task(1);

    return 0;
}