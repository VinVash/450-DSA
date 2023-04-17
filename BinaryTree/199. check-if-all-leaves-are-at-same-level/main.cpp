#include <bits/stdc++.h>
using namespace std;

bool checkUtil(Node *node, int level, int *leafLevel) {
	if(node == nullptr) return true;

	// if current node is leaf.
	if(!node->left && !node->right) {
		
		// update the leaflevel initially.
		if(*leafLevel == 0) {
			*leafLevel = level;
			return true;
		}

		// check if level and leaflevel is same.
		return (level == *leafLevel);
	}

	return checkUtil(node->left, level+1, leafLevel) && checkUtil(node->right, level+1, leafLevel);
}

bool check(Node *root) {
	int leafLevel = 0;
	int level = 0;

	return checkUtil(root, level, leafLevel);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}