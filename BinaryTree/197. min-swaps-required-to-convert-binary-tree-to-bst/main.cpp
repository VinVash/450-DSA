#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

void inorderIterative(Node *root, vector<int> &res) {
	if(root == nullptr)
		return;

	stack<Node *> stk;
	Node *p = root;

	while(p || stk.size()) {
		if(p) {
			res.push_back(p->data);
			p = p->left;
		} else {
			p = stk.top();
			stk.pop();
			res.push_back(p->data);
			p = p->right;
		}
	}
}

int minSwaps(vector<int> &nums) {
	int n = nums.size();
	int ans = 0;

	vector<int> temp(nums.begin(), nums.end());

	unordered_map<int, int> h;

	sort(temp.begin(), temp.end());

	for(int i = 0; i < n; i++)
		h[arr[i]] = i; // positions of elements in original array.

	for(int i = 0; i < n; i++) {
		if(arr[i] != temp[i]) {
			ans++;
			int initial = arr[i];

			swap(arr, i, h[temp[i]]);

			h[initial] = h[temp[i]];
			h[temp[i]] = i;
		}
	}

	return ans;
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