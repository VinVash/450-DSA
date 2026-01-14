int height(Node* node){
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = height(node->left);
        int rDepth = height(node->right);
     
        /* use the larger one */
        return 1 + max(lDepth, rDepth);
    }
}