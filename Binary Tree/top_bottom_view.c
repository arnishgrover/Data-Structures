/*
Initialise the array sent to this function with all zeroes.
Or if the tree contains the value 0, then intialise the array sent with some value which might not be present in the array to ensure proper functioning
Since this logic uses overwriting the value of the array in case of top view
*/



void top(Node *root, int d, int *a, int size) {
    if(root == NULL) {
        return;
    }
    if(a[d+size] == 0) {
        a[d+size] = root->data;
    }
    top(root->left, d-1, a,size);
    top(root->right, d+1, a,size);

}
void bottom(Node *root, int d, int *a, int size) {
    if(root == NULL) {
        return;
    }
    a[d+size] = root->data;
    bottom(root->left, d-1, a,size);
    bottom(root->right, d+1, a,size);
}

