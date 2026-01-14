#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1, a1+n);
    sort(a2, a2+m);
    
    if(m > n)
        return "No";
        
    int i = 0; // pointer of a2.
    int j = 0; // pointer of a1.
    
    while(i < m && j < n) {
        if(a2[i] > a1[j])
            j++;
        else if(a2[i] < a1[j])
            return "No";
        else {
            i++;
            j++;
        }
    }
    
    if(i < m)
        return "No";
    else
        return "Yes";
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int m, n;
	cin >> m >> n;

	vector<int> a1(m);
	vector<int> a2(n);

	for(int i = 0; i < m; i++)
	    cin >> a1[i];

	for(int i = 0; i < n; i++)
	    cin >> a2[i];

	cout << isSubset(a1, a2, m, n) << endl;

	return 0;
}