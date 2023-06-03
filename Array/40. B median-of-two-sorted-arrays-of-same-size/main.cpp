#include <bits/stdc++.h>
using namespace std;

int median(int arr[], int n) {
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

// just part iterators for slicing in vectors.
int getMedian(int ar1[], int ar2[], int n) {
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

    int m1 = median(ar1, n); /* get the median of the first array */
    int m2 = median(ar2, n); /* get the median of the second array */
  
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
  
    /* if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
  
    /* if m1 > m2 then median must exist in ar1[....m1] and ar2[m2....] */
    if (n % 2 == 0)
        return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    return getMedian(ar2 + n/2, ar1, n - n/2);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;

    int ar1[n];
    int ar2[n];

    for(int i = 0; i < n; i++)
        cin >> ar1[i];

    for(int i = 0; i < n; i++)
        cin >> ar2[i];

    cout << getMedian(ar1, ar2, n) << endl;


	return 0;
}