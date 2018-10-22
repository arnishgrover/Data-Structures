void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    inorder(root->left);
    inorder(root->right);
}
void postorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->data);
}
