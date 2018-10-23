/* Construction using given PreOrder and InOrder traversal arrays */
int in1 = 0;
Node * constructIPre(int ino[], int pre[], int low, int high) {
    if(low > high) {
        return NULL;
    }
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = pre[in1];
    int i;
    for(i = low; i <= high; i++) {
        if(ino[i] == pre[in1]) {
            break;
        }
    }
    in1++;
    nn->left = constructIPre(ino, pre, low, i-1);
    nn->right = constructIPre(ino, pre, i+1, high);
    return nn;

}

/* Construction using given PostOrder and InOrder traversal arrays */
int in2 = sizeof(ino)/sizeof(int) - 1;
Node * constructIPre(int ino[], int pos[], int low, int high) {
    if(low > high) {
        return NULL;
    }
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = pre[in1];
    int i;
    for(i = low; i <= high; i++) {
        if(ino[i] == pre[in1]) {
            break;
        }
    }
    in2--;
    nn->right = constructIPre(ino, pre, low, i-1);
    nn->left = constructIPre(ino, pre, i+1, high);
    return nn;

}
