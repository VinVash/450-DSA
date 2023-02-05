#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};



int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    cout << "Hello World" << endl;

	return 0;
}