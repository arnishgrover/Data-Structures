Node * mirror(Node *root) {           // returns a new tree that is mirror of the tree passed without changing the passed tree
    if(root == NULL) {
        return NULL;
    }
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = root->data;
    nn->left = mirror(root->right);
    nn->right = mirror(root->left);
    return nn;

}
