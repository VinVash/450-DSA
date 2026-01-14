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

// Auxiliary Space: O(N^2), since we are hashing a string for
// each node(n nodes are there) and length of this string can
// be of the order of N.
string inorder(Node *node, unordered_map<string, int> &m) {
	if(node == nullptr)
		return "";

	string str = "(";
	str += inorder(node->left, m);
	str += to_string(node->data);
	str += inorder(node->right, m);
	str += ")";

	if(m[str] == 1)
		cout << node->data << " ";

	m[str]++;

	return str;
}

void printAllDups(Node *root) {
	unordered_map<string, int> m;
	inorder(root, m);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node *root = nullptr;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(2);
	root->right->left->left = new Node(4);
	root->right->right = new Node(4);

	printAllDups(root);

	return 0;
}