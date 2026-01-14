// Have a look at the all the solutions.
// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> findCommon(vector<int> &A, vector<int> &B, vector<int> &C) {
	vector<int> res; // ans vector.

	int i = 0, j = 0, k = 0; // starting indices of the three vectors.

	int prev1, prev2, prev3; // pointers for tracking the previous elements
							 // of the three vectors to avoid duplicates;

	prev1 = prev2 = prev3 = INT_MIN;

	int n1 = A.size(), n2 = B.size(), n3 = C.size();

	while(i < n1 && j < n2 && k < n3) {
		while(A[i] == prev1 && i < n1)
			i++;

		while(B[j] == prev2 && j < n2)
			j++;

		while(C[k] == prev3 && k < n3)
			k++;

		if(A[i] == B[j] && B[j] == C[k]) {
			res.push_back(A[i]);
			prev1 = A[i++];
			prev2 = B[j++];
			prev3 = C[k++];
		}
		else if (A[i] < B[j])
			prev1 = A[i++];
		else if(B[j] < C[k])
			prev2 = B[j++];
		else
			prev3 = C[k++];
	}
	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> A(n1);
    vector<int> B(n2);
    vector<int> C(n3);

    for (int i = 0; i < n1; ++i)
    	cin >> A[i];

    for (int i = 0; i < n2; ++i)
    	cin >> B[i];

    for (int i = 0; i < n3; ++i)
    	cin >> C[i];

    vector<int> res = findCommon(A, B, C);

    for(int i = 0; i < res.size(); i++)
    	cout << res[i] << " ";
    cout << endl;


	return 0;
}