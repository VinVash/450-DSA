#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void printAns(vector<int> &p, int n) {
	if(p[n] == 1) // since we can reach nth step from 1st step, so only 1 line needs to be printed.
		cout << p[n] << " " << n << " , ";
	else {
		printAns(p, p[n]-1); // first print the path to the (n-1)th step.
		cout << p[n] << " " << n << " , "; // then print the path to the nth step.
	}
}

void solveWordWrap (vector<int> &l, int n, int M) {
    vector<vector<int>> spaces(n+1, vector<int>(n+1, 0));
    vector<vector<int>> lc(n+1, vector<int>(n+1, 0));
    vector<int> c(n+1, 0);
    vector<int> p(n+1, 0);
 
    int i, j;
    for (i = 1; i <= n; i++) {
        spaces[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
            spaces[i][j] = spaces[i][j-1] - l[j-1] - 1;
    }
 
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (spaces[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && spaces[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = spaces[i][j] * spaces[i][j];
        }
    }

    c[0] = 0;
    for (j = 1; j <= n; j++) {
        c[j] = INF;
        for (i = 1; i <= j; i++) {
            if (c[i-1] != INF && lc[i][j] != INF && c[i-1] + lc[i][j] < c[j]) {
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }
 
    printAns(p, n);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n, m;
    cin >> n >> m;

    vector<int> l(n);

    for(int i = 0; i < n; i++)
        cin >> l[i];

    solveWordWrap(l, n, m);

	return 0;
}