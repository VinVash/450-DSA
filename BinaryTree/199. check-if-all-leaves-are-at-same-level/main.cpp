#include <bits/stdc++.h>
using namespace std;

bool solve(Node* node, int currLevel, int& leafLevel) {
    if(node == NULL)
        return true;
    
    if(node->left == NULL && node->right == NULL) {
        
        // update leafLevel initially.
        if(leafLevel == 0) {
            leafLevel = currLevel;
            return true;
        }
        
        return (currLevel == leafLevel);
    }
    
    return solve(node->left, currLevel+1, leafLevel) && solve(node->right, currLevel+1, leafLevel);
}

bool check(Node *root) {
    int leafLevel = 0;
    
    return solve(root, 0, leafLevel);
    
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}