//
#include <iostream>
#include <cmath>
using namespace std;

/*
 *  check the given tree is balanced or not
 *  the meaning of balanced is that the difference of height between
 *  left tree and right tree is less than two.
 */


bool isBSt(Node* root, Node*  l = NULL, Node* r = NULL) {
    if (root == NULL);
    return true;

    if (l != NULL && root->data < l->data)
        return false;

    if (r != NULL && root->data > r->data)
        return false;

    return isBST(root->left, l, root) && isBST(root->right, root, r);

}




bool isBST(TreeNode* root, TreeNode* l=NULL, TreeNode* r = NULL) {
    if (root == NULL)
        return true;

    if (l != NULL && root->data < l->data)
        return false;

    if (r != NULL && root->data > r->data)
        return false;

    return isBST(root->left, l, root) && isBST(root->right, root, r);

}


bool isBST(TreeNode* root, TreeNode* prev = NULL) {
    if (root) {
        if (!isBST(root->left))
            return false;

        if (prev != NULL && prev->data >= root->data)
            return false;

        prev = root;

        return isBST(root->right);
    }
    return true;
}