#include <bits/stdc++.h>
using namespace std;

int toSumTree2(Node *node) {
	if(!node) return 0; // returning for leaf nodes call.

	int old_val = node->data;

	node->data = toSumTree2(node->left) + toSumTree2(node->right);

	return node->data + old_val;
}
  
    
void toSumTree(Node *node) {
    toSumTree2(node);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}