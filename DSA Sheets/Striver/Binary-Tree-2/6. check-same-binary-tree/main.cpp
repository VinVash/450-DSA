#include <bits/stdc++.h>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    // base cases.
    if(p == nullptr && q == nullptr)
        return true;
    if((p && !q) || (!p && q))
        return false;
    
    bool boolSame = p->val == q->val;
    bool boolLSame = isSameTree(p->left, q->left);
    bool boolRSame = isSameTree(p->right, q->right);

    return boolSame && boolLSame && boolRSame;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}