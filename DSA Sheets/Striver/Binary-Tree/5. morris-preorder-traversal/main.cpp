#include <bits/stdc++.h>
using namespace std;

// consider p as the curr pointer.
vector<int> morrisInorder(TreeNode* root) {
	vector<int> inorder;
	TreeNode* p = root;

	while(p != NULL) {
		if(p->left == NULL) {
			inorder.push_back(p->val);
			p = p->right;
		} else {
			TreeNode* prev = p->left;
			while(prev->right && prev->right != p) {
				prev = prev->right;
			}

			if(prev->right == NULL) {
				prev->right = p;
				inorder.push_back(p->val);
				p = p->left;
			} else {
				prev->right = NULL;
				p = p->right;
			}
		}
	}

	return inorder;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}