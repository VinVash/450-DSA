#include <bits/stdc++.h>
using namespace std;

int maxPathDown(TreeNode* root, int& maxi) {
    if(root == NULL)
        return 0;

    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));
    maxi = max(left + right + root->val, maxi);

    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    
    return maxi;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}