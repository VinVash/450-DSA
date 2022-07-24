#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};

Node* newNode(int key) {
    Node* node = new Node();
    node -> left = node -> right = NULL;
    node -> data = key;
    return node;
}

void topView(Node *root) {
	if(root == nullptr)
		return;

	queue<Node *> q;
	map<int, int> m;
	int hd = 0;
	root->hd = hd;

	q.push(root);

	while(q.size()) {
		hd = root->hd;

		if(m.count(hd) == 0)
			m[hd] = root->data;
		if(root->left) {
			root->left->hd = hd-1;
			q.push(root->left);
		}

		if(root->right) {
			root->right->hd = hd+1;
			q.push(root->right);
		}

		q.pop();
		root = q.front();
	}

	for (auto i = m.begin(); i != m.end(); i++) {
        cout << i -> second << " ";
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> right = newNode(4);
    root -> left -> right -> right = newNode(5);
    root -> left -> right -> right -> right = newNode(6);

    topView(root);

	return 0;
}