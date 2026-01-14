#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		if(left) {
			delete left;
		}
		if(right) {
			delete right;
		}
	}
};

int findCeil(BinaryTreeNode<int> *node, int x) {
	int res = -1; // stores the final ans.
    
    while(root) {
        if(root->val == X) {
            res = root->val;
            return res;
        } else if(root->val > X) {
            res = root->val;
            root = root->left;
        } else {
            root = root->right;
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