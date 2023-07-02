#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

int maxIndexDiff(int arr[], int n) {
    int hig[n];
    int low[n];
    
    low[0]=arr[0];
    hig[n-1]=arr[n-1];
    
    for(int i=1; i<=n; i++)
        low[i] = min(low[i-1], arr[i]);
    for(int i=n-2; i>=0; i--)
        hig[i] = max(hig[i+1], arr[i]);
    
    int i=0;
    int j=0;
    int ma=0;
    while(i<n&&j<=n)
    {
        while(j<n && hig[j]>=low[i])
        j++;
        ma=max((j-i-1), ma);
        i++;
    }
    return ma;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}