int check(Node *t1, Node *t2) {
    if(t1 && t2) {
        if(t1->data != t2->data) {
            return 0;
        }
        return (check(t1->left, t2->left) && check(t1->right, t2->right));
    }
    if(t1 == NULL && t2 == NULL) {
        return 1;
    }
    return 0;

}
