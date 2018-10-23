/* 
Diameter is defined as the longest span of nodes that are continously connected
Here max_h is the max height of the tree after the function has finished its execution
Intially pass max_h = 0
*/

void diameter(Node *root, int *max_h) {
    if(root == NULL) return;
    int a = height(root->left);
    int b = height(root->right);
    if(a+b+1 > *max_h) {
        *max_h = a+b+1;
    }
    diameter(root->left, max_h);
    diameter(root->right, max_h);
}
