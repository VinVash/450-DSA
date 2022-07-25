#include <bits/stdc++.h>
using namespace std;

const char MARKER = '$';

struct Node {
	char key;
	Node *left, *right;

	Node(char ch) {
		this->key = ch;
		this->left = this->right = nullptr;
	}
};

unordered_set<string> subtrees;

string duplicateSubtreesUtil(Node *node) {
	string s = "";

	if(!node)
		return s + '$';

	string lStr = duplicateSubtreesUtil(node->left);
	if(lStr.compare("") == 0)
		return s;

	string rStr = duplicateSubtreesUtil(node->right);
	if(rStr.compare("") == 0)
		return s;

	// Since the size of hash of leaf node will be 3, therefore we would need to
	// search for subtrees which have hash size greater than 3, because leaf nodes
	// are not considered as subtrees.
	s = s + node->key + lStr + rStr;

	if(s.size() > 3 && subtrees.find(s) != subtrees.end())
		return "";

	subtrees.insert(s);

	return s;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left= new Node('D');

	string str = duplicateSubtreesUtil(root);

	(str.compare("") == 0) ? cout << "Yes" : cout <<  "No";
	cout << endl;

	return 0;
}