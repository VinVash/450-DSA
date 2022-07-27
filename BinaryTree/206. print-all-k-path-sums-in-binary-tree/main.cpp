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

void printVector(vector<int> &v, int i) {
	for(int j = i; j < v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}

// Time: O(n*h*h) as the largest path is the height of the tree.
void printKPathUtil(Node *node, vector<int> &path, int k) {
	if(node == nullptr) return;

	path.push_back(node->data);

	printKPathUtil(node->left, path, k);
	printKPathUtil(node->right, path, k);

	int f = 0;
	// We are adding bottom-up, if we get a path with sum k at index i, that means
	// the path is starting at i. Print the vector starting from index i.
	for(int i = path.size()-1; i >= 0; i--) {
		f += path[i];

		if(f == k)
			printVector(path, i); // since we got a path starting from node i 
	}

	path.pop_back(); // remove the added element since we want to get a new path in the next recursion.
}

void printKPath(Node *root, int k) {
	vector<int> path; // initialise an empty vector.
	printKPathUtil(root, path, k);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
  
    int k = 5;
    printKPath(root, k);

	return 0;
}