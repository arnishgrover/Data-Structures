Node *insert(Node *root, int data) {
    if(root == NULL) {
        struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
        nn->data = data;
        nn->left = nn->right = NULL;
        return nn;
    }
    if( root->data > data ) {
        root->left = insert(root->left,data);
    }
    else {
        root->right = insert(root->right,data);
    }
    return root;
}
