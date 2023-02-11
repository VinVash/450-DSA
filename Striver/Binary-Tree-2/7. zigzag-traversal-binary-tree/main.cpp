#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zigZagTraversal(TreeNode* root) {
	vector<vector<int>> ans;

	if(root == NULL)
		return ans;

	queue<TreeNode*> q;
	q.push(root);
	bool flag = false;

	while(!q.empty()) {
		int n = q.size();
		vector<int> level;
		for(int i = 0; i < n; i++) {
			TreeNode* node = q.front();
			q.pop();
			level.push_back(node->val);

			if(node->left != NULL)
				q.push(node->left);

			if(node->right != NULL)
				q.push(node->right);
		}

		flag = !flag;
		if(flag == false)
			reverse(level.begin(), level.end());

		ans.push_back(level);
	}

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}