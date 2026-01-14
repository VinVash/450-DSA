void mirrorify(node *root, node** mirror) {
	if(root == nullptr) {
		mirror = nullptr;
		return;
	}

	*mirror = createNode(root->val);
	mirrorify(root->left, &((*mirror)->right));
	mirrorify(root->right, &((*mirror)->left));
}

node* mirrorTree(node *root) {
	if(root == NULL)
		return root;

	node *t = root->left;
	root->left = root->right;
	root->right = t;

	if(root->left)
		mirrorTree(root->left);
	if(root->right)
		mirrorTree(root->right);

	return root;
}

int main() {
	node* tree = createNode(5);
	tree->left = createNode(3);
	tree->right = createNode(6);
	tree->left->left = createNode(2);
	tree->left>right = createNode(4);

	node* mirror = nullptr;
	mirrorify(tree, &mirror);
}