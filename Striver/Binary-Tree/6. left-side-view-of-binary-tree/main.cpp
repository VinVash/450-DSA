#include <bits/stdc++.h>
using namespace std;

void leftView(TreeNode<int>* root, int level, int *max_level, vector<int>& ans) {
    if(root == nullptr)
        return;

    if(*max_level < level) {
        ans.push_back(root->data);
        *max_level = level;
    }

    leftView(root->left, level+1, max_level, ans);
    leftView(root->right, level+1, max_level, ans);
}

vector<int> getLeftView(TreeNode<int> *root) {
    vector<int> ans;
    int max_level = 0;
    leftView(root, 1, &max_level, ans);

    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}