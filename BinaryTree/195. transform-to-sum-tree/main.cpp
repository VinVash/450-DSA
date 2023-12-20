#include <bits/stdc++.h>
using namespace std;

int solve(Node *node) {
	if(!node) return 0; // returning for leaf nodes call.

	int old_val = node->data;

	node->data = solve(node->left) + solve(node->right);

	return node->data + old_val;
}
  
    
void toSumTree(Node *node) {
    solve(node);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}