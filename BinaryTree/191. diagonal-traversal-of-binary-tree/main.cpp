#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node *newNode(int val) {
	Node *node = new Node;
	node->data = val;
	node->left = node->right = nullptr;
	return node;
}

vector<vector<int>> res;
void diagonalTraversal(Node *root) {
	if(root == nullptr)
		return;

	queue<Node *> q;
	q.push(root);

	while(!q.empty()) {
		int n = q.size();
		vector<int> ans;

		while(n) {
			Node *temp = q.front();
			q.pop();

			while(temp) {
				ans.push_back(temp->data);

				if(temp->left)
					q.push(temp->left);

				temp = temp->right;
			}

			n--;
		}

		res.push_back(ans);
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
     
    diagonalTraversal(root);

    for(auto i: res) {
    	for(auto j: i) {
    		cout << j << " ";
    	}
    	cout << endl;
    }

	return 0;
}