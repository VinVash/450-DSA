#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

void inorderTraversal(vector<int>& A, vector<int>& result, int i, int n) {
    if (i < n) {
        inorderTraversal(A, result, 2 * i + 1, n); // Visit left child
        result.push_back(A[i]); // Visit node
        inorderTraversal(A, result, 2 * i + 2, n); // Visit right child
    }
}

int minSwapsToSort(vector<int>& A) {
    
    int n = A.size();
    vector<pair<int, int>> arrPos;
    for (int i = 0; i < n; i++) {
        arrPos.push_back({A[i], i});
    }
    sort(arrPos.begin(), arrPos.end());

    vector<bool> visited(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arrPos[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j].second;
            cycle_size++;
        }

        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

int minSwaps(vector<int>&A, int n){
    vector<int> inorder;
    inorderTraversal(A, inorder, 0, A.size()); // get the inorder traversal
    return minSwapsToSort(inorder); // find min swaps to sort this (inorder) array
    }

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> inorder;

	inorderIterative(root, inorder);

	cout << minSwaps(inorder) << endl;

	return 0;
}