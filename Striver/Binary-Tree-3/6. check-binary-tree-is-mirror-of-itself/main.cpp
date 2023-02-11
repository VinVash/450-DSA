#include <bits/stdc++.h>
using namespace std;

void mirror(Node* node) {
    if(node == NULL)
        return;
        
    Node*temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    mirror(node->left);
    mirror(node->right);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}