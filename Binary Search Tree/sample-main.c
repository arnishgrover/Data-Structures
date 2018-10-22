
int main() {
    Node *root = NULL;
    int i;
    for(i = 10; i >= 0; i -= 2) {
        root = insert(root,i);
    }
    for(i = 1; i < 10; i+= 2) {
        root = insert(root,i);
    }

    for(i = 11; i < 20; i += 2) {
        root = insert(root,i);
    }
    for(i = 12; i < 20; i+= 2) {
        root = insert(root,i);
    }
    inorder(root);
    printf("\n");
    root = delete(root, 5);
    inorder(root);
    Node *temp = LCA(root, 4, 19);
    printf("LCA of given nodes is: %d\n", temp->data);
    printf("\n\n");
    int p[50];
    paths(root,p,0);
    

    Node *m = mirror(root);
    inorder(m);
    printf("\n %d %d %d\n", check(root,m), check(root,root), check(m,m));
    assert(check(root,m) == 0 );
    assert(check(root,root) == 1 );
    assert(check(m,m) == 1 );
    return 0;


}
    