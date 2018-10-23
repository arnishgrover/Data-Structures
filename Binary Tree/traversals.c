/* PostOrder traversal */

void postorder(Node *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* PreOrder traversal */

void preorder(Node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* InOrder traversal */


void inorder(Node *root) {
    if(root == NULL) return;
    preorder(root->left);
    printf("%d ", root->data);
    preorder(root->right);
}
