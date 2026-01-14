#include <bits/stdc++.h>
using namespace std;

int inSequence(int A, int B, int C){
    long long diff = B - A;
    if(diff * C < 0) return 0;
    
    if(C == 0) {
        if(A == B) return 1;
        return 0;
    }
    
    if(diff % C == 0)
        return 1;
    
    return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int a, b, c;
	cin >> a >> b >> c;

	cout << inSequence(a, b, c) << endl;

	return 0;
}