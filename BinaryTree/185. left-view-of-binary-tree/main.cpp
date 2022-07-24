#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

struct Node *newNode(int item) {
    struct Node *temp = (struct Node *)malloc(
                        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void leftViewUtil(Node *root, int level, int *max_level) {
	if(root == nullptr) return;

	if(*max_level < level) {
		cout << root->data << " ";
		*max_level = level;
	}

	leftViewUtil(root->left, level+1, max_level);
	leftViewUtil(root->right, level+1, max_level);
}

void leftView(Node *root) {
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

void printLeftView(Node *root) {
	if(!root)
		return;

	queue<Node *> q;
	q.push(root);

	while(q.size()) {
		int n = q.size();

		for(int i = 1; i <= n; i++) {
			Node *temp = q.front();
			q.pop();

			if(i == 1)
				cout << temp->data << " ";

			if(temp->left)
				q.push(temp->left);

			if(temp->right)
				q.push(temp->right);
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    leftView(root);
    cout << endl;

    printLeftView(root);

	return 0;
}