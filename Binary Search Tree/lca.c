Node * LCA (Node * root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > a && root->data > b) {
        return LCA(root->left, a, b);
    }
    else if(root->data < a && root->data < b) {
        return LCA(root->right, a, b);
    }
    return root;
}
