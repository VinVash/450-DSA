#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
	T val;
	TreeNode<T> *left;
	TreeNode<t> *right;

	TreeNode(T val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

int floorInBST(TreeNode<int> * root, int X) {

    int res = -1; // stores the final ans.
    
    while(root) {
        if(root->val == X) {
            res = root->val;
            return res;
        } else if(root->val < X) {
            res = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}