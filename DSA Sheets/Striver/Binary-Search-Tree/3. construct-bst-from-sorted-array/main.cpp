#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode<int> *node, vector<int> &ans) {
	if(node == nullptr)
		return;

	inorder(node->left, ans);
	ans.push_back(node->data);
	inorder(node->right, ans);
}

TreeNode<int>* build(vector<int>&arr,int l,int h) {
    if(l > h)
        return NULL;
    int mid = (l + h) / 2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = build(arr,l,mid-1);
    root->right = build(arr,mid+1,h);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) {
	return build(arr, 0, n-1);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}