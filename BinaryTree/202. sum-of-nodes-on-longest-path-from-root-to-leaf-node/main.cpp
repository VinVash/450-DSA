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

void sumOfLongRootToLeafPath(Node *node, int sum, int len, int &max_len, int &max_sum) {
	if(node == nullptr) { // means we have traversed from root to the leaf path.

		if(len > max_len) {
			max_len = len;
			max_sum = sum;
		} else if(max_len == len && sum > max_sum)
			max_sum = sum;

		return;
	}

	sumOfLongRootToLeafPath(node->left, sum + node->data, len+1, max_len, max_sum);
	sumOfLongRootToLeafPath(node->right, sum + node->data, len+1, max_len, max_sum);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = new Node(4);         /*        4        */
    root->left = new Node(2);         /*       / \       */
    root->right = new Node(5);        /*      2   5      */
    root->left->left = new Node(7);   /*     / \ / \     */
    root->left->right = new Node(1);  /*    7  1 2  3    */
    root->right->left = new Node(2);  /*      /          */
    root->right->right = new Node(3); /*     6           */
    root->left->right->left = new Node(6);

    int max_sum = INT_MIN, max_len = 0;
  
    sumOfLongRootToLeafPath(root, 0, 0, max_len, max_sum);
    cout << max_sum << endl;

	return 0;
}