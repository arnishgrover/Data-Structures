void paths(Node *root, int p[], int index) {            // For the initial run the index is 0 and array is empty
    if(root == NULL) {
        return;
    }
    p[index++] = root->data;
    if(root->left == NULL && root->right == NULL) {

        int i;
        for(i = 0; i< index; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
        return;
    }
    else {
        paths(root->left, p, index);
        paths(root->right, p, index);
    }

}
