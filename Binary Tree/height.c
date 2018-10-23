int max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}
int height(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return 1+ max(height(root->left), height(root->right));
}
