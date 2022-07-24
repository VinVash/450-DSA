#include <bits/stdc++.h>
using namespace std;

struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};

bool isInside(int x, int y, int N) {
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepsToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int N) {
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 
    // queue for storing states of knight in board
    queue<cell> q;
 
    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));
 
    cell t;
    int x, y;
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

    // visit starting state
    dp[knightPos[0]][knightPos[1]] = true;
 
    // loop till the queue gets empty.
    while (!q.empty()) {
        t = q.front();
        q.pop();
 
        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
 
        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
 
            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !dp[x][y]) {
                dp[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }

    return -1; // if not reachable.
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int N = 30;
	vector<int> knightPos {1, 1};
	vector<int> targetPos {30, 30};

	cout << minStepsToReachTarget(knightPos, targetPos, N) << endl;

	return 0;
}
