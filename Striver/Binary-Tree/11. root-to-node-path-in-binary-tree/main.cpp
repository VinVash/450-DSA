#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void fun(TreeNode* root, int B, vector<int> v, vector<int> &ans) {
    if(root == NULL)
        return;
        
    v.push_back(root->val);
    
    if(B == root->val) {
        ans = v;
        return;
    }
    
    fun(root->left, B, v, ans);
    fun(root->right, B, v, ans);
}
 
vector<int> solve(TreeNode* A, int B) {
    vector<int> v;
    vector<int> ans;
    
    fun(A, B, v, ans);
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}