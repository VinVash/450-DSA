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

unordered_map<string, int> mp;

string serialize(Node *root) {
    if (!root) return "#";

    string s = "(" + serialize(root->left) + to_string(root->data) + serialize(root->right) + ")";
    mp[s]++;
    return s;
}

int dupSub(Node *root) {
    mp.clear();
    serialize(root);

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second >= 2 && it->first.size() > 3)
            return 1;
    }

    return 0;
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




    // 1st appraoch
	string str = duplicateSubtreesUtil(root);

	(str.compare("") == 0) ? cout << "Yes" : cout <<  "No";
	cout << endl;



	// 2nd appraoch
	mp.clear();
	solve(root);
	for(auto it: mp) {
		if(it.second >= 2)
			cout << "Yes" << endl;
	}
	cout << "No" << endl;




	return 0;
}