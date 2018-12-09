int dia(Node *root) {
    if(root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return max(1 + lh + rh, max(dia(root->left), dia(root->right)));
}

/* This can be broken in 3 parts:
    1. Length of path passing through the current node 1 + lh + rh
    2. Diamter of the left subtree
    3. Diamter of right subtree
    
    The max out of these is the required answer
    */
