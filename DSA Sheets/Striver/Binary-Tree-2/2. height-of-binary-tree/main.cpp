#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int height(Node *node) {
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = height(node->left);
        int rDepth = height(node->right);

        /* use the larger one */
        return 1 + max(lDepth, rDepth);
    }
}

void height(TreeNode* root, int currHeight, int* maxDepth) {
	if(root == nullptr)
		return;

	if(currHeight > *maxDepth) {
		*maxDepth = currHeight;
	}

	height(root->left, currHeight+1, maxDepth);
	height(root->right, currHeight+1, maxDepth);
}

int maxDepth(TreeNode* root) {

	if(root == nullptr) {
		return 0;
	}

	int maxDepth = 1; // since there is at least one node in the tree.

	height(root, 1, &maxDepth);

	return maxDepth;

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}