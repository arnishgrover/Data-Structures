int findMin(Node * root) {
    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
Node* delete(Node *root, int data) {
    if(root->data == data) {
        if(root->left == NULL) {
            return root->right;
        }
        else if(root->right == NULL) {
            return root->left;
        }
        else {
            int x = findMin(root->right);
            root->data = x;
            root->right = delete(root->right,x);
            return root;
        }

    }
    else if(root->data > data) {
        root->left = delete(root->left, data);
    }
    else {
        root->right = delete(root->right, data);
    }
    return root;
}
