#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

void inOrder(TreeNode *node, vector<int> &ans) {
	if(node == nullptr)
		return;

	inOrder(node->left, ans);
	ans.push_back(node->val);
	inOrder(node->right, ans);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> ans;

    inOrder(root, ans);
    int n = ans.size();

    return ans[n-k];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	return 0;
}