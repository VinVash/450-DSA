#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int val) {
		this->data = val;
		this->left = this->right = nullptr;
	}
};

int sum(struct Node *root) {
    if (root == NULL)
        return 0;
     
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(Node *node) {
	int lsum, rsum;

	if(node == nullptr || (node->left == nullptr && node->right == nullptr))
		return 1;

	lsum = sum(node->left);
	rsum = sum(node->right);

	if((node->data == lsum + rsum) && isSumTree(node->left) && isSumTree(node->right))
		return 1;

	return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);

    if(isSumTree(root))
    	cout << "Yes" << endl;
    else
    	cout << "No" << endl;

	return 0;
}