#include <bits/stdc++.h>
using namespace std;

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1; i <= n; i++)
        ans = ans * number;
    return ans;
}

double findNthRootOfM(int n, int m) {
	double low = 1;
    double high = m;
    double eps = 1e-6;
    
    while(high - low > eps) {
        double mid = (low + high) / 2;
        if(multiply(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    
    return high;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}