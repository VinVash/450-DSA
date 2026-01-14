#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(BinaryTreeNode<int> *node, vector<int> &vec) {
    if(node == nullptr)
        return;

    inorder(node->left, vec);
    vec.push_back(node->data);
    inorder(node->right, vec);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> ans;

    inorder(root, ans);

    int n = ans.size();

    int l = 0, r = n-1;

    while(l < r) {
        int sum = ans[l] + ans[r];
        if(sum < k) {
            l++;
        } else if(sum > k) {
            r--;
        } else {
            return true;
        }
    }

    return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}